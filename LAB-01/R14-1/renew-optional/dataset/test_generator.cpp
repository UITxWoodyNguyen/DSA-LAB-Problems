#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <random>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_range(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

void make_test(int test_id, const string &filepath) {
    ofstream out(filepath);
    
    long long a, k, b, m, n;
    
    if (test_id == 1) {
        // Sample
        a = 2; k = 4; b = 3; m = 3; n = 25;
    } else if (test_id <= 5) {
        a = rand_range(1, 10);
        b = rand_range(1, 10);
        k = rand_range(2, 10);
        m = rand_range(2, 10);
        n = rand_range(1, 1000);
    } else if (test_id <= 15) {
        a = rand_range(1, 100);
        b = rand_range(1, 100);
        k = rand_range(2, 100);
        m = rand_range(2, 100);
        n = rand_range(1, 100000);
    } else if (test_id <= 30) {
        a = rand_range(1, 10000);
        b = rand_range(1, 10000);
        k = rand_range(2, 10000);
        m = rand_range(2, 10000);
        n = rand_range(1, 1000000000LL);
    } else {
        a = rand_range(1, 1000000000LL);
        b = rand_range(1, 1000000000LL);
        k = rand_range(2, 1000000000000000000LL);
        m = rand_range(2, 1000000000000000000LL);
        n = rand_range(1, 1000000000000000000LL);
    }
    
    out << a << " " << k << " " << b << " " << m << " " << n << "\n";
    out.close();
}

int main() {
    fs::create_directories("input");

    const int TOTAL_TESTS = 50;
    for (int i = 1; i <= TOTAL_TESTS; ++i) {
        stringstream ss;
        ss << "input/" << setfill('0') << setw(2) << i << ".inp";
        make_test(i, ss.str());
        cout << "[OK] Generated: " << ss.str() << "\n";
    }
    return 0;
}