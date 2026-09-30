#!/usr/bin/env python3
"""
Local Grader / Auto-judge for Competitive Programming
Supports template compliance, compilation, execution with time/memory limits,
and detailed reporting with color-coded output.
Cross-platform: Windows, Linux (Ubuntu, Kali, Debian, Mint, etc.), macOS
"""

import argparse
import os
import re
import sys
import subprocess
import tempfile
import shutil
import time
import signal
import platform
from pathlib import Path
from typing import Optional, Tuple, List, Dict, Any
from dataclasses import dataclass
from enum import Enum
import json

try:
    import psutil
    PSUTIL_AVAILABLE = True
except ImportError:
    PSUTIL_AVAILABLE = False

try:
    from tabulate import tabulate
    TABULATE_AVAILABLE = True
except ImportError:
    TABULATE_AVAILABLE = False

try:
    from rich.console import Console
    from rich.table import Table
    from rich.text import Text
    RICH_AVAILABLE = True
except ImportError:
    RICH_AVAILABLE = False

# Platform detection
IS_WINDOWS = platform.system() == "Windows"
IS_LINUX = platform.system() == "Linux"
IS_MACOS = platform.system() == "Darwin"
IS_UNIX = IS_LINUX or IS_MACOS

# Binary names
BINARY_NAME = "submission.exe" if IS_WINDOWS else "submission"
COMPILER = "g++"


class Verdict(Enum):
    AC = "AC"
    WA = "WA"
    TLE = "TLE"
    MLE = "MLE"
    RTE = "RTE"
    CE = "CE"
    REJECTED = "REJECTED"
    SKIPPED = "SKIPPED"


@dataclass
class TestResult:
    test_id: str
    verdict: Verdict
    time_ms: float
    memory_mb: float
    details: str = ""
    expected: str = ""
    actual: str = ""


@dataclass
class ProblemConfig:
    time_limit_sec: float = 1.0
    memory_limit_mb: int = 256
    float_epsilon: float = 1e-6
    custom_checker: Optional[str] = None


# Enable Windows ANSI color support
if IS_WINDOWS:
    try:
        import ctypes
        kernel32 = ctypes.windll.kernel32
        kernel32.SetConsoleMode(kernel32.GetStdHandle(-11), 7)
        kernel32.SetConsoleMode(kernel32.GetStdHandle(-12), 7)
    except Exception:
        pass

class Colors:
    GREEN = "\033[92m"
    RED = "\033[91m"
    YELLOW = "\033[93m"
    BLUE = "\033[94m"
    MAGENTA = "\033[95m"
    CYAN = "\033[96m"
    WHITE = "\033[97m"
    BOLD = "\033[1m"
    RESET = "\033[0m"
    
    @classmethod
    def enabled(cls) -> bool:
        # On Windows, check if we can use ANSI colors
        if IS_WINDOWS:
            # Check if running in a terminal that supports ANSI
            try:
                import ctypes
                kernel32 = ctypes.windll.kernel32
                handle = kernel32.GetStdHandle(-11)
                mode = ctypes.c_ulong()
                kernel32.GetConsoleMode(handle, ctypes.byref(mode))
                return bool(mode.value & 0x0004)  # ENABLE_VIRTUAL_TERMINAL_PROCESSING
            except Exception:
                return False
        return sys.stdout.isatty()


def colorize(text: str, color: str) -> str:
    if Colors.enabled():
        return f"{color}{text}{Colors.RESET}"
    return text


def verdict_color(verdict: Verdict) -> str:
    colors = {
        Verdict.AC: Colors.GREEN,
        Verdict.WA: Colors.RED,
        Verdict.TLE: Colors.YELLOW,
        Verdict.MLE: Colors.MAGENTA,
        Verdict.RTE: Colors.RED,
        Verdict.CE: Colors.RED,
        Verdict.REJECTED: Colors.RED,
        Verdict.SKIPPED: Colors.CYAN,
    }
    return colors.get(verdict, Colors.WHITE)


def normalize_output(text: str) -> str:
    """Normalize whitespace for comparison."""
    text = text.replace('\r\n', '\n').replace('\r', '\n')
    lines = [line.rstrip() for line in text.split('\n')]
    while lines and lines[-1] == '':
        lines.pop()
    return '\n'.join(lines)


def compare_outputs(expected: str, actual: str, epsilon: float = 1e-6) -> bool:
    """Compare outputs with optional float tolerance."""
    expected_norm = normalize_output(expected)
    actual_norm = normalize_output(actual)
    
    if expected_norm == actual_norm:
        return True
    
    try:
        exp_tokens = expected_norm.split()
        act_tokens = actual_norm.split()
        
        if len(exp_tokens) != len(act_tokens):
            return False
        
        for e, a in zip(exp_tokens, act_tokens):
            try:
                ef = float(e)
                af = float(a)
                if abs(ef - af) > epsilon * max(1.0, abs(ef)):
                    return False
            except ValueError:
                if e != a:
                    return False
        return True
    except Exception:
        return False


def extract_template_structure(template_path: Path) -> Dict[str, Any]:
    """Extract required structure from template.cpp."""
    content = template_path.read_text(encoding='utf-8', errors='ignore')
    
    structure = {
        'required_functions': [],
        'required_classes': [],
        'required_includes': [],
        'begin_marker': False,
        'end_marker': False,
        'forbidden_patterns': []
    }
    
    begin_match = re.search(r'//\s*BEGIN\s+TEMPLATE', content, re.IGNORECASE)
    end_match = re.search(r'//\s*END\s+TEMPLATE', content, re.IGNORECASE)
    structure['begin_marker'] = begin_match is not None
    structure['end_marker'] = end_match is not None
    
    func_pattern = r'(?:template\s*<[^>]*>\s*)?(?:inline\s+)?(?:static\s+)?(?:\w+(?:\s*::\s*\w+)*)\s+(\w+)\s*\([^)]*\)\s*(?:const\s*)?(?:override\s*)?(?:final\s*)?(?:\s*=\s*0)?\s*;'
    for match in re.finditer(func_pattern, content):
        structure['required_functions'].append(match.group(1))
    
    class_pattern = r'class\s+(\w+)'
    for match in re.finditer(class_pattern, content):
        structure['required_classes'].append(match.group(1))
    
    include_pattern = r'#include\s*[<"]([^>"]+)[>"]'
    for match in re.finditer(include_pattern, content):
        structure['required_includes'].append(match.group(1))
    
    return structure


def check_template_compliance(submission_path: Path, template_structure: Dict[str, Any]) -> Tuple[bool, str]:
    """Check if submission follows template structure."""
    content = submission_path.read_text(encoding='utf-8', errors='ignore')
    errors = []
    
    if template_structure['begin_marker'] and template_structure['end_marker']:
        begin_match = re.search(r'//\s*BEGIN\s+TEMPLATE', content, re.IGNORECASE)
        end_match = re.search(r'//\s*END\s+TEMPLATE', content, re.IGNORECASE)
        if not begin_match or not end_match:
            errors.append("Missing BEGIN/END TEMPLATE markers")
        elif begin_match.start() > end_match.start():
            errors.append("BEGIN TEMPLATE appears after END TEMPLATE")
    
    for func in template_structure['required_functions']:
        pattern = rf'\b{re.escape(func)}\s*\('
        if not re.search(pattern, content):
            errors.append(f"Missing required function: {func}")
    
    for cls in template_structure['required_classes']:
        pattern = rf'\bclass\s+{re.escape(cls)}\b'
        if not re.search(pattern, content):
            errors.append(f"Missing required class: {cls}")
    
    for inc in template_structure['required_includes']:
        pattern = rf'#include\s*[<"]{re.escape(inc)}[>"]'
        if not re.search(pattern, content):
            errors.append(f"Missing required include: {inc}")
    
    if errors:
        return False, "; ".join(errors)
    return True, ""


def parse_description_md(description_path: Path) -> ProblemConfig:
    """Parse description.md for time/memory limits and other config."""
    config = ProblemConfig()
    
    if not description_path.exists():
        return config
    
    content = description_path.read_text(encoding='utf-8', errors='ignore')
    
    time_patterns = [
        r'Time\s*limit\s*:\s*([\d\.]+)\s*(s|ms|seconds?|milliseconds?)',
        r'Time\s*Limit\s*:\s*([\d\.]+)\s*(s|ms|seconds?|milliseconds?)',
        r'time\s*limit\s*[:=]\s*([\d\.]+)\s*(s|ms|seconds?|milliseconds?)',
    ]
    
    for pattern in time_patterns:
        match = re.search(pattern, content, re.IGNORECASE)
        if match:
            value = float(match.group(1))
            unit = match.group(2).lower()
            if unit.startswith('m'):
                config.time_limit_sec = value / 1000.0
            else:
                config.time_limit_sec = value
            break
    
    mem_patterns = [
        r'Memory\s*limit\s*:\s*(\d+)\s*(MB|MiB|MB|mebibytes?)',
        r'Memory\s*Limit\s*:\s*(\d+)\s*(MB|MiB|MB|mebibytes?)',
        r'memory\s*limit\s*[:=]\s*(\d+)\s*(MB|MiB|MB|mebibytes?)',
    ]
    
    for pattern in mem_patterns:
        match = re.search(pattern, content, re.IGNORECASE)
        if match:
            config.memory_limit_mb = int(match.group(1))
            break
    
    eps_patterns = [
        r'(?:absolute|relative)\s+error\s+(?:less\s+than|<=?)\s*10\s*\^\s*\{?(-?\d+)\}?',
        r'epsilon\s*[:=]\s*10\s*\^\s*\{?(-?\d+)\}?',
        r'sai\s+số\s+10\s*\^\s*\{?(-?\d+)\}?',
    ]
    
    for pattern in eps_patterns:
        match = re.search(pattern, content, re.IGNORECASE)
        if match:
            config.float_epsilon = 10 ** int(match.group(1))
            break
    
    return config


def compile_submission(submission_path: Path, binary_path: Path) -> Tuple[bool, str]:
    """Compile submission.cpp with g++ (cross-platform)."""
    # On Linux/macOS, -static causes issues with glibc/pthreads
    # On Windows, -static works fine with MinGW
    if IS_WINDOWS:
        cmd = [
            COMPILER, '-O3', '-std=c++17', '-pipe',
            '-static', '-s',
            str(submission_path), '-o', str(binary_path)
        ]
    else:
        cmd = [
            COMPILER, '-O3', '-std=c++17', '-pipe',
            '-pthread',
            str(submission_path), '-o', str(binary_path)
        ]
    
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        if result.returncode != 0:
            return False, result.stderr.strip()
        return True, ""
    except subprocess.TimeoutExpired:
        return False, "Compilation timeout (60s)"
    except FileNotFoundError:
        return False, f"{COMPILER} not found in PATH. Install build-essential (Linux) or MinGW (Windows)"
    except Exception as e:
        return False, f"Compilation error: {e}"


def run_testcase(binary_path: Path, input_path: Path, output_path: Path,
                 time_limit_sec: float, memory_limit_mb: int) -> TestResult:
    """Run a single test case with time/memory monitoring (cross-platform)."""
    test_id = input_path.stem
    
    input_data = input_path.read_text(encoding='utf-8', errors='ignore')
    
    peak_memory = 0.0
    start_time = time.perf_counter()
    
    # Cross-platform binary execution
    if IS_WINDOWS:
        run_cmd = [str(binary_path)]
    else:
        run_cmd = [f"./{binary_path.name}"]
        # Ensure binary is executable
        try:
            binary_path.chmod(0o755)
        except Exception:
            pass
    
    try:
        proc = subprocess.Popen(
            run_cmd,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            cwd=str(binary_path.parent)
        )
        
        try:
            stdout, stderr = proc.communicate(input=input_data, timeout=time_limit_sec + 0.5)
            elapsed = time.perf_counter() - start_time
            
            if PSUTIL_AVAILABLE:
                try:
                    p = psutil.Process(proc.pid)
                    peak_memory = p.memory_info().rss / 1024 / 1024
                    for child in p.children(recursive=True):
                        peak_memory = max(peak_memory, child.memory_info().rss / 1024 / 1024)
                except (psutil.NoSuchProcess, psutil.AccessDenied):
                    pass
            
            if proc.returncode != 0:
                return TestResult(
                    test_id=test_id,
                    verdict=Verdict.RTE,
                    time_ms=elapsed * 1000,
                    memory_mb=peak_memory,
                    details=f"Exit code: {proc.returncode}. Stderr: {stderr[:200]}"
                )
            
            if elapsed > time_limit_sec:
                return TestResult(
                    test_id=test_id,
                    verdict=Verdict.TLE,
                    time_ms=elapsed * 1000,
                    memory_mb=peak_memory,
                    details=f"Time limit exceeded ({elapsed:.3f}s > {time_limit_sec}s)"
                )
            
            if peak_memory > memory_limit_mb:
                return TestResult(
                    test_id=test_id,
                    verdict=Verdict.MLE,
                    time_ms=elapsed * 1000,
                    memory_mb=peak_memory,
                    details=f"Memory limit exceeded ({peak_memory:.1f}MB > {memory_limit_mb}MB)"
                )
            
            expected = output_path.read_text(encoding='utf-8', errors='ignore') if output_path.exists() else ""
            
            if compare_outputs(expected, stdout):
                return TestResult(
                    test_id=test_id,
                    verdict=Verdict.AC,
                    time_ms=elapsed * 1000,
                    memory_mb=peak_memory
                )
            else:
                return TestResult(
                    test_id=test_id,
                    verdict=Verdict.WA,
                    time_ms=elapsed * 1000,
                    memory_mb=peak_memory,
                    details="Output mismatch",
                    expected=normalize_output(expected)[:200],
                    actual=normalize_output(stdout)[:200]
                )
                
        except subprocess.TimeoutExpired:
            proc.kill()
            try:
                proc.communicate(timeout=1)
            except:
                pass
            elapsed = time.perf_counter() - start_time
            return TestResult(
                test_id=test_id,
                verdict=Verdict.TLE,
                time_ms=elapsed * 1000,
                memory_mb=peak_memory,
                details=f"Timeout after {time_limit_sec}s"
            )
            
    except Exception as e:
        elapsed = time.perf_counter() - start_time
        return TestResult(
            test_id=test_id,
            verdict=Verdict.RTE,
            time_ms=elapsed * 1000,
            memory_mb=peak_memory,
            details=f"Execution error: {e}"
        )


def print_results_table(results: List[TestResult], config: ProblemConfig):
    """Print results table using best available method."""
    if RICH_AVAILABLE:
        print_results_rich(results, config)
    elif TABULATE_AVAILABLE:
        print_results_tabulate(results)
    else:
        print_results_simple(results)


def print_results_rich(results: List[TestResult], config: ProblemConfig):
    console = Console()
    table = Table(title="Judging Results", show_header=True, header_style="bold")
    table.add_column("Test ID", style="cyan", justify="center")
    table.add_column("Status", justify="center")
    table.add_column("Time (ms)", justify="right", style="blue")
    table.add_column("Memory (MB)", justify="right", style="magenta")
    table.add_column("Details", style="dim")
    
    for r in results:
        status_text = Text(r.verdict.value, style=verdict_color(r.verdict))
        time_str = f"{r.time_ms:.1f}"
        if r.verdict == Verdict.TLE:
            time_str = colorize(time_str, Colors.YELLOW)
        mem_str = f"{r.memory_mb:.1f}"
        if r.verdict == Verdict.MLE:
            mem_str = colorize(mem_str, Colors.MAGENTA)
        
        details = r.details
        if r.verdict == Verdict.WA:
            details += f"\n  Exp: {r.expected}\n  Got: {r.actual}"
        
        table.add_row(r.test_id, status_text, time_str, mem_str, details)
    
    console.print(table)
    
    ac_count = sum(1 for r in results if r.verdict == Verdict.AC)
    total = len(results)
    percentage = (ac_count / total * 100) if total > 0 else 0
    score_color = Colors.GREEN if percentage == 100 else Colors.YELLOW if percentage >= 50 else Colors.RED
    console.print(f"\n[bold]Score: {ac_count}/{total} [{percentage:.1f}%][/bold]")


def print_results_tabulate(results: List[TestResult]):
    headers = ["Test ID", "Status", "Time (ms)", "Memory (MB)", "Details"]
    rows = []
    for r in results:
        status = colorize(r.verdict.value, verdict_color(r.verdict))
        time_str = f"{r.time_ms:.1f}"
        mem_str = f"{r.memory_mb:.1f}"
        rows.append([r.test_id, status, time_str, mem_str, r.details])
    print(tabulate(rows, headers=headers, tablefmt="grid"))


def print_results_simple(results: List[TestResult]):
    print(f"{'Test ID':<10} {'Status':<10} {'Time(ms)':>10} {'Mem(MB)':>10} Details")
    print("-" * 80)
    for r in results:
        status = colorize(f"{r.verdict.value:<10}", verdict_color(r.verdict))
        print(f"{r.test_id:<10} {status} {r.time_ms:>10.1f} {r.memory_mb:>10.1f} {r.details}")
    
    ac_count = sum(1 for r in results if r.verdict == Verdict.AC)
    total = len(results)
    percentage = (ac_count / total * 100) if total > 0 else 0
    score_str = f"Score: {ac_count}/{total} [{percentage:.1f}%]"
    print(colorize(score_str, Colors.GREEN if percentage == 100 else Colors.YELLOW if percentage >= 50 else Colors.RED))


def find_test_files(problem_dir: Path) -> List[Tuple[Path, Path]]:
    """Find matching input/output test files."""
    input_dir = problem_dir / "dataset" / "input"
    output_dir = problem_dir / "dataset" / "output"
    
    if not input_dir.exists():
        return []
    
    test_files = []
    for inp_file in sorted(input_dir.glob("*.inp")):
        out_file = output_dir / f"{inp_file.stem}.out"
        if out_file.exists():
            test_files.append((inp_file, out_file))
        else:
            test_files.append((inp_file, None))
    
    return test_files


def main():
    parser = argparse.ArgumentParser(
        description="Local Grader / Auto-judge for Competitive Programming",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python judge.py --sub submission.cpp --problem ./LAB-01/R14-2/pharmacy-stock-alert
  python judge.py -s main.cpp -p . -t template.cpp
        """
    )
    parser.add_argument('--sub', '--submission', dest='submission',
                        required=True, help='Path to submission.cpp')
    parser.add_argument('--problem', '-p', dest='problem_dir',
                        default='.', help='Problem directory (default: current)')
    parser.add_argument('--template', '-t', dest='template',
                        help='Path to template.cpp (optional)')
    parser.add_argument('--no-clean', action='store_true',
                        help='Keep compiled binary after judging')
    parser.add_argument('--verbose', '-v', action='store_true',
                        help='Verbose output')
    
    args = parser.parse_args()
    
    submission_path = Path(args.submission).resolve()
    problem_dir = Path(args.problem_dir).resolve()
    
    if not submission_path.exists():
        print(colorize(f"[ERROR] Submission file not found: {submission_path}", Colors.RED))
        sys.exit(1)
    
    if not problem_dir.exists():
        print(colorize(f"[ERROR] Problem directory not found: {problem_dir}", Colors.RED))
        sys.exit(1)
    
    template_path = None
    if args.template:
        template_path = Path(args.template).resolve()
    else:
        default_template = problem_dir / "template.cpp"
        if default_template.exists():
            template_path = default_template
    
    description_path = problem_dir / "description.md"
    config = parse_description_md(description_path)
    
    if args.verbose:
        print(f"Problem: {problem_dir.name}")
        print(f"Submission: {submission_path}")
        print(f"Template: {template_path if template_path else 'None'}")
        print(f"Time Limit: {config.time_limit_sec}s")
        print(f"Memory Limit: {config.memory_limit_mb}MB")
        print(f"Float Epsilon: {config.float_epsilon}")
        print()
    
    if template_path and template_path.exists():
        if args.verbose:
            print("Checking template compliance...")
        template_structure = extract_template_structure(template_path)
        compliant, error = check_template_compliance(submission_path, template_structure)
        if not compliant:
            print(colorize(f"[REJECTED] Submission does not follow the required template!", Colors.RED))
            print(colorize(f"Reason: {error}", Colors.RED))
            sys.exit(2)
        if args.verbose:
            print(colorize("[OK] Template compliance check passed", Colors.GREEN))
    
    with tempfile.TemporaryDirectory() as tmpdir:
        binary_path = Path(tmpdir) / "submission"
        
        if args.verbose:
            print("Compiling...")
        
        success, error = compile_submission(submission_path, binary_path)
        if not success:
            print(colorize("[CE] Compilation Error", Colors.RED))
            print(colorize(error, Colors.RED))
            sys.exit(3)
        
        if args.verbose:
            print(colorize("[OK] Compilation successful", Colors.GREEN))
        
        test_files = find_test_files(problem_dir)
        if not test_files:
            print(colorize("[WARNING] No test cases found in dataset/input/", Colors.YELLOW))
            sys.exit(0)
        
        if args.verbose:
            print(f"Found {len(test_files)} test case(s)")
            print("Running tests...\n")
        
        results = []
        for inp_file, out_file in test_files:
            if out_file is None:
                result = TestResult(
                    test_id=inp_file.stem,
                    verdict=Verdict.SKIPPED,
                    time_ms=0,
                    memory_mb=0,
                    details="No corresponding .out file"
                )
                results.append(result)
                continue
            
            result = run_testcase(binary_path, inp_file, out_file,
                                 config.time_limit_sec, config.memory_limit_mb)
            results.append(result)
            
            if args.verbose:
                status = colorize(result.verdict.value, verdict_color(result.verdict))
                print(f"  {inp_file.stem}: {status} ({result.time_ms:.1f}ms, {result.memory_mb:.1f}MB)")
        
        print()
        print_results_table(results, config)
        
        if not args.no_clean and binary_path.exists():
            binary_path.unlink()
    
    ac_count = sum(1 for r in results if r.verdict == Verdict.AC)
    if ac_count == len(results):
        sys.exit(0)
    else:
        sys.exit(1)


if __name__ == "__main__":
    main()