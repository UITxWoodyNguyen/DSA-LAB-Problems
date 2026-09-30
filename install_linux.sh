#!/bin/bash
# DSA Judge - Linux Installation Script
# Supports: Ubuntu, Debian, Kali Linux, Linux Mint, Pop!_OS, etc.

set -e

echo "========================================"
echo "DSA Judge - Linux Installer"
echo "========================================"
echo ""

# Detect distribution
if [ -f /etc/os-release ]; then
    . /etc/os-release
    echo "Detected: $PRETTY_NAME"
else
    echo "Unknown Linux distribution"
fi

echo ""
echo "Installing system dependencies..."

# Install build tools and g++
if command -v apt-get &> /dev/null; then
    # Debian/Ubuntu/Kali/Mint/Pop!_OS
    sudo apt-get update
    sudo apt-get install -y build-essential g++ python3 python3-pip python3-venv
elif command -v dnf &> /dev/null; then
    # Fedora/RHEL/CentOS
    sudo dnf install -y gcc-c++ make python3 python3-pip
elif command -v pacman &> /dev/null; then
    # Arch/Manjaro
    sudo pacman -S --needed base-devel gcc python python-pip
elif command -v zypper &> /dev/null; then
    # openSUSE
    sudo zypper install -y gcc-c++ make python3 python3-pip
else
    echo "WARNING: Unknown package manager. Please install g++, make, python3, pip manually."
fi

echo ""
echo "Installing Python dependencies..."

# Create virtual environment (recommended)
python3 -m venv venv
source venv/bin/activate

# Upgrade pip
pip install --upgrade pip

# Install package in development mode
pip install -e .

echo ""
echo "========================================"
echo "Installation complete!"
echo "========================================"
echo ""
echo "To use DSA Judge:"
echo "  1. Activate virtual environment: source venv/bin/activate"
echo "  2. Run interactive mode: dsa-judge"
echo "  3. Or direct mode: dsa-judge -s submission.cpp -p ./problem -v"
echo ""
echo "To generate test cases for a problem:"
echo "  cd LAB-01/R14-2/<problem>/dataset"
echo "  g++ -std=c++17 -O3 -pthread test_generator.cpp -o test_generator"
echo "  ./test_generator"
echo ""
echo "To generate expected outputs:"
echo "  g++ -std=c++17 -O3 -pthread output_generator.cpp -o output_generator"
echo "  ./output_generator"
echo ""