#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int main() {
    fs::create_directories("output");

    // Cross-platform compilation
#ifdef _WIN32
    int compile_status = system("g++ -O3 -std=c++17 -pipe -static -s ../solution.cpp -o ../solution.exe");
    string binary_name = "solution.exe";
    string run_prefix = "..\\solution.exe";
#else
    int compile_status = system("g++ -O3 -std=c++17 -pipe -pthread ../solution.cpp -o ../solution");
    string binary_name = "solution";
    string run_prefix = "./solution";
#endif

    if (compile_status != 0) {
        cerr << "[ERROR] Khong the bien dich ../solution.cpp!\n";
        return 1;
    }

    const int TOTAL_TESTS = 50;
    for (int i = 1; i <= TOTAL_TESTS; ++i) {
        stringstream in_ss, out_ss, cmd;
        in_ss << "input/" << setfill('0') << setw(2) << i << ".inp";
        out_ss << "output/" << setfill('0') << setw(2) << i << ".out";

        if (!fs::exists(in_ss.str())) {
            cout << "[SKIP] File " << in_ss.str() << " khong ton tai.\n";
            continue;
        }

        // Cross-platform execution
#ifdef _WIN32
        cmd << run_prefix << " < " << in_ss.str() << " > " << out_ss.str();
#else
        cmd << "cd .. && ./" << binary_name << " < dataset/" << in_ss.str() << " > dataset/" << out_ss.str();
#endif
        system(cmd.str().c_str());

        cout << "[OK] Generated: " << out_ss.str() << "\n";
    }
    return 0;
}