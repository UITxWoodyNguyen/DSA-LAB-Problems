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
    
    int n;
    if (test_id <= 5) {
        n = rand_range(1, 20);
    } else if (test_id <= 15) {
        n = rand_range(20, 1000);
    } else if (test_id <= 30) {
        n = rand_range(1000, 50000);
    } else {
        n = rand_range(50000, 100000);
    }
    
    out << n << "\n";
    
    vector<long long> arr;
    if (test_id == 1) {
        arr = {12, 14, 0, 41, 567, 0, -545};
        n = 7;
    } else if (test_id <= 5) {
        for (int i = 0; i < n; ++i) arr.push_back(rand_range(-1000000000LL, 1000000000LL));
    } else if (test_id <= 10) {
        for (int i = 0; i < n; ++i) arr.push_back(i);
    } else if (test_id <= 15) {
        for (int i = 0; i < n; ++i) arr.push_back(n - i);
    } else {
        for (int i = 0; i < n; ++i) arr.push_back(rand_range(-1000000000LL, 1000000000LL));
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