#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <random>
#include <chrono>
#include <filesystem>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_range(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

void make_test(int test_id, const string &filepath) {
    ofstream out(filepath);
    
    long long X;
    int n;
    
    if (test_id <= 5) {
        n = rand_range(0, 10);
        X = rand_range(-10, 20);
    } else if (test_id <= 15) {
        n = rand_range(10, 1000);
        X = rand_range(-1000000000LL, 1000000000LL);
    } else if (test_id <= 30) {
        n = rand_range(1000, 100000);
        X = rand_range(-1000000000LL, 1000000000LL);
    } else {
        n = rand_range(100000, 150000);
        X = rand_range(-1000000000LL, 1000000000LL);
    }
    
    out << X << "\n";
    out << n << "\n";
    
    vector<long long> arr;
    if (test_id <= 5) {
        // Small descending array
        long long val = rand_range(10, 100);
        for (int i = 0; i < n; ++i) {
            arr.push_back(val - i * rand_range(1, 5));
        }
    } else if (test_id <= 10) {
        // Array with target present
        arr.push_back(X);
        long long val = X + rand_range(1, 10);
        for (int i = 1; i < n; ++i) {
            val -= rand_range(1, 5);
            arr.push_back(val);
        }
    } else if (test_id <= 15) {
        // Array without target
        long long val = rand_range(100, 1000);
        for (int i = 0; i < n; ++i) {
            arr.push_back(val - i * rand_range(1, 10));
        }
    } else {
        // Large random descending
        long long val = rand_range(1000000000LL, 1000000000LL);
        for (int i = 0; i < n; ++i) {
            arr.push_back(val - i * rand_range(1, 100));
        }
    }
    
    for (int i = 0; i < n; ++i) {
        out << arr[i] << (i == n-1 ? "\n" : " ");
    }
    
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