#!/usr/bin/env python3
"""
DSA Judge - Interactive CLI Tool
Local Grader / Auto-judge for Competitive Programming
"""

import argparse
import sys
import os
from pathlib import Path
from typing import Optional, List, Tuple

# Add parent directory to path for imports
sys.path.insert(0, str(Path(__file__).parent.parent))

from judge import (
    main as judge_main,
    parse_description_md,
    extract_template_structure,
    check_template_compliance,
    compile_submission,
    run_testcase,
    find_test_files,
    print_results_table,
    ProblemConfig,
    TestResult,
    Verdict,
)
from judge import Colors, colorize, verdict_color


class DSAJudgeCLI:
    """Interactive CLI for DSA Judge."""

    def __init__(self):
        self.submission_path: Optional[Path] = None
        self.problem_dir: Optional[Path] = None
        self.template_path: Optional[Path] = None
        self.verbose: bool = False
        self.no_clean: bool = False

    def print_banner(self):
        """Print welcome banner."""
        banner = """
+================================================================+
|                    DSA JUDGE v1.0.0                           |
|         Local Grader / Auto-judge for CP                      |
|              Competitive Programming Lab                      |
+================================================================+
"""
        print(colorize(banner, Colors.CYAN))

    def print_menu(self):
        """Print main menu."""
        print("\n" + "=" * 60)
        print(colorize("MAIN MENU", Colors.BOLD + Colors.BLUE))
        print("=" * 60)
        print(f"  {colorize('1.', Colors.YELLOW)} Set Submission File")
        print(f"  {colorize('2.', Colors.YELLOW)} Set Problem Directory")
        print(f"  {colorize('3.', Colors.YELLOW)} Set Template File (optional)")
        print(f"  {colorize('4.', Colors.YELLOW)} Toggle Verbose Mode: {colorize('ON' if self.verbose else 'OFF', Colors.GREEN if self.verbose else Colors.RED)}")
        print(f"  {colorize('5.', Colors.YELLOW)} Toggle Keep Binary: {colorize('ON' if self.no_clean else 'OFF', Colors.GREEN if self.no_clean else Colors.RED)}")
        print(f"  {colorize('6.', Colors.YELLOW)} View Current Settings")
        print(f"  {colorize('7.', Colors.GREEN)} Run Judge")
        print(f"  {colorize('8.', Colors.RED)} Exit")
        print("=" * 60)

    def print_settings(self):
        """Print current settings."""
        print("\n" + "-" * 60)
        print(colorize("CURRENT SETTINGS", Colors.BOLD + Colors.BLUE))
        print("-" * 60)
        print(f"  Submission: {colorize(str(self.submission_path) if self.submission_path else 'Not set', Colors.CYAN if self.submission_path else Colors.RED)}")
        print(f"  Problem Dir: {colorize(str(self.problem_dir) if self.problem_dir else 'Not set', Colors.CYAN if self.problem_dir else Colors.RED)}")
        print(f"  Template: {colorize(str(self.template_path) if self.template_path else 'Not set (auto-detect)', Colors.CYAN if self.template_path else Colors.YELLOW)}")
        print(f"  Verbose: {colorize('ON' if self.verbose else 'OFF', Colors.GREEN if self.verbose else Colors.RED)}")
        print(f"  Keep Binary: {colorize('ON' if self.no_clean else 'OFF', Colors.GREEN if self.no_clean else Colors.RED)}")
        print("-" * 60)

    def get_input(self, prompt: str, default: str = "") -> str:
        """Get user input with optional default."""
        if default:
            user_input = input(f"{prompt} [{default}]: ").strip()
            return user_input if user_input else default
        return input(f"{prompt}: ").strip()

    def select_file(self, prompt: str, must_exist: bool = True, extensions: List[str] = None) -> Optional[Path]:
        """Interactive file selection."""
        while True:
            path_str = self.get_input(prompt)
            if not path_str:
                return None

            path = Path(path_str).expanduser().resolve()

            if must_exist and not path.exists():
                print(colorize(f"  [ERROR] File not found: {path}", Colors.RED))
                continue

            if extensions and path.suffix.lower() not in extensions:
                print(colorize(f"  [WARNING] Expected extension: {', '.join(extensions)}", Colors.YELLOW))

            return path

    def select_directory(self, prompt: str, must_exist: bool = True) -> Optional[Path]:
        """Interactive directory selection."""
        while True:
            path_str = self.get_input(prompt)
            if not path_str:
                return None

            path = Path(path_str).expanduser().resolve()

            if must_exist and not path.exists():
                print(colorize(f"  [ERROR] Directory not found: {path}", Colors.RED))
                continue

            if must_exist and not path.is_dir():
                print(colorize(f"  [ERROR] Not a directory: {path}", Colors.RED))
                continue

            return path

    def set_submission(self):
        """Set submission file."""
        print("\n" + colorize("SET SUBMISSION FILE", Colors.BOLD))
        path = self.select_file("Enter path to submission.cpp", must_exist=True, extensions=['.cpp', '.cc', '.cxx'])
        if path:
            self.submission_path = path
            print(colorize(f"  [OK] Submission set to: {path}", Colors.GREEN))

    def set_problem_dir(self):
        """Set problem directory."""
        print("\n" + colorize("SET PROBLEM DIRECTORY", Colors.BOLD))
        path = self.select_directory("Enter path to problem directory", must_exist=True)
        if path:
            # Verify it has description.md
            desc = path / "description.md"
            if not desc.exists():
                print(colorize(f"  [WARNING] No description.md found in {path}", Colors.YELLOW))
            self.problem_dir = path
            print(colorize(f"  [OK] Problem directory set to: {path}", Colors.GREEN))

    def set_template(self):
        """Set template file."""
        print("\n" + colorize("SET TEMPLATE FILE (Optional)", Colors.BOLD))
        print("  Leave empty to auto-detect template.cpp in problem directory")
        path = self.select_file("Enter path to template.cpp", must_exist=False, extensions=['.cpp', '.cc', '.cxx'])
        if path:
            self.template_path = path
            print(colorize(f"  [OK] Template set to: {path}", Colors.GREEN))
        else:
            self.template_path = None
            print(colorize("  [OK] Template cleared (will auto-detect)", Colors.GREEN))

    def toggle_verbose(self):
        """Toggle verbose mode."""
        self.verbose = not self.verbose
        print(colorize(f"  Verbose mode: {'ON' if self.verbose else 'OFF'}", Colors.GREEN if self.verbose else Colors.RED))

    def toggle_no_clean(self):
        """Toggle keep binary mode."""
        self.no_clean = not self.no_clean
        print(colorize(f"  Keep binary: {'ON' if self.no_clean else 'OFF'}", Colors.GREEN if self.no_clean else Colors.RED))

    def validate_settings(self) -> bool:
        """Validate all required settings."""
        errors = []
        if not self.submission_path:
            errors.append("Submission file not set")
        if not self.problem_dir:
            errors.append("Problem directory not set")
        if self.submission_path and not self.submission_path.exists():
            errors.append(f"Submission file not found: {self.submission_path}")
        if self.problem_dir and not self.problem_dir.exists():
            errors.append(f"Problem directory not found: {self.problem_dir}")
        if self.template_path and not self.template_path.exists():
            errors.append(f"Template file not found: {self.template_path}")

        if errors:
            print(colorize("\n[ERROR] Please fix the following:", Colors.RED))
            for err in errors:
                print(colorize(f"  - {err}", Colors.RED))
            return False
        return True

    def run_judge_interactive(self):
        """Run judge with current settings."""
        if not self.validate_settings():
            return

        print("\n" + colorize("RUNNING JUDGE...", Colors.BOLD + Colors.GREEN))

        # Build argv for judge_main
        argv = [
            'judge.py',
            '--sub', str(self.submission_path),
            '--problem', str(self.problem_dir),
        ]
        if self.template_path:
            argv.extend(['--template', str(self.template_path)])
        if self.verbose:
            argv.append('--verbose')
        if self.no_clean:
            argv.append('--no-clean')

        # Save and restore sys.argv
        old_argv = sys.argv
        sys.argv = argv
        try:
            judge_main()
        except SystemExit as e:
            exit_code = e.code if isinstance(e.code, int) else 1
            if exit_code == 0:
                print(colorize("\n[SUCCESS] All tests passed!", Colors.GREEN))
            elif exit_code == 2:
                print(colorize("\n[REJECTED] Template compliance failed!", Colors.RED))
            elif exit_code == 3:
                print(colorize("\n[CE] Compilation error!", Colors.RED))
            else:
                print(colorize(f"\n[FAILED] Some tests failed (exit code: {exit_code})", Colors.RED))
        finally:
            sys.argv = old_argv

    def run_interactive(self):
        """Main interactive loop."""
        self.print_banner()

        while True:
            self.print_menu()
            choice = self.get_input("Select option (1-8)")

            if choice == '1':
                self.set_submission()
            elif choice == '2':
                self.set_problem_dir()
            elif choice == '3':
                self.set_template()
            elif choice == '4':
                self.toggle_verbose()
            elif choice == '5':
                self.toggle_no_clean()
            elif choice == '6':
                self.print_settings()
            elif choice == '7':
                self.run_judge_interactive()
            elif choice == '8' or choice.lower() == 'q':
                print(colorize("\nGoodbye!", Colors.CYAN))
                break
            else:
                print(colorize("  [ERROR] Invalid option. Please select 1-8.", Colors.RED))


def main():
    """Main entry point for DSA Judge CLI."""
    parser = argparse.ArgumentParser(
        prog='dsa-judge',
        description='DSA Judge - Local Grader for Competitive Programming',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  dsa-judge                    # Interactive mode
  dsa-judge -s sub.cpp -p ./problem  # Direct mode
  dsa-judge --help             # Show help

Interactive mode allows you to:
  - Set submission file
  - Set problem directory  
  - Set template file (optional)
  - Toggle verbose/keep-binary options
  - Run judge with visual feedback
        """
    )
    parser.add_argument('-s', '--sub', '--submission', dest='submission',
                        help='Path to submission.cpp')
    parser.add_argument('-p', '--problem', dest='problem_dir',
                        help='Problem directory path')
    parser.add_argument('-t', '--template', dest='template',
                        help='Path to template.cpp (optional)')
    parser.add_argument('-v', '--verbose', action='store_true',
                        help='Verbose output')
    parser.add_argument('--no-clean', action='store_true',
                        help='Keep compiled binary after judging')
    parser.add_argument('--version', action='version', version='DSA Judge 1.0.0')

    args = parser.parse_args()

    # If no arguments provided, run interactive mode
    if not any([args.submission, args.problem_dir, args.template]):
        cli = DSAJudgeCLI()
        cli.run_interactive()
        return

    # Direct mode - delegate to judge.py
    argv = ['judge.py']
    if args.submission:
        argv.extend(['--sub', args.submission])
    if args.problem_dir:
        argv.extend(['--problem', args.problem_dir])
    if args.template:
        argv.extend(['--template', args.template])
    if args.verbose:
        argv.append('--verbose')
    if args.no_clean:
        argv.append('--no-clean')

    old_argv = sys.argv
    sys.argv = argv
    try:
        judge_main()
    except SystemExit as e:
        sys.exit(e.code if isinstance(e.code, int) else 1)
    finally:
        sys.argv = old_argv


if __name__ == '__main__':
    main()