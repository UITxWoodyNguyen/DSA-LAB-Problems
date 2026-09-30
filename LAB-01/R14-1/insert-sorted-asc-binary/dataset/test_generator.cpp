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
        n = rand_range(0, 20);
        X = rand_range(-100, 100);
    } else if (test_id <= 15) {
        n = rand_range(20, 1000);
        X = rand_range(-1000000, 1000000);
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
    if (test_id == 1) {
        arr = {1, 4, 6, 7, 9, 10, 15};
        n = 7;
    } else if (test_id == 2) {
        arr = {1, 4, 6, 7, 9, 10, 15};
        n = 7;
        X = 0;
    } else if (test_id == 3) {
        n = 0;
    } else if (test_id <= 10) {
        long long val = rand_range(-1000, 1000);
        for (int i = 0; i < n; ++i) {
            val += rand_range(1, 10);
            arr.push_back(val);
        }
    } else if (test_id <= 20) {
        arr.push_back(X - 10);
        for (int i = 1; i < n; ++i) {
            arr.push_back(arr.back() + rand_range(1, 10));
        }
    } else if (test_id <= 30) {
        for (int i = 0; i < n; ++i) {
            arr.push_back(rand_range(-1000, 1000));
        }
        sort(arr.begin(), arr.end());
        X = arr.back() + rand_range(1, 10);
    } else {
        for (int i = 0; i < n; ++i) {
            arr.push_back(rand_range(-1000000000LL, 1000000000LL));
        }
        sort(arr.begin(), arr.end());
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