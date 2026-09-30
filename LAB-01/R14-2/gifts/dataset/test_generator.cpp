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
    long long x;
    if (test_id == 1) {
        n = 2;
        x = 10;
    } else if (test_id <= 5) {
        n = rand_range(2, 10);
        x = rand_range(2, 100);
    } else if (test_id <= 15) {
        n = rand_range(10, 1000);
        x = rand_range(100, 10000);
    } else if (test_id <= 30) {
        n = rand_range(1000, 100000);
        x = rand_range(10000, 1000000000LL);
    } else {
        n = rand_range(100000, 100000);
        x = rand_range(100000000, 1000000000LL);
    }
    
    out << n << " " << x << "\n";
    
    vector<long long> a;
    if (test_id == 1) {
        a = {5, 3, 10, 2, 4, 9};
        n = 6;
        x = 18;
        out.seekp(0);
        out << n << " " << x << "\n";
    } else if (test_id == 2) {
        for (int i = 0; i < n; ++i) a.push_back(1);
    } else if (test_id == 3) {
        for (int i = 0; i < n; ++i) a.push_back(x + 1);
    } else if (test_id == 4) {
        a.push_back(x / 2);
        a.push_back(x / 2);
        for (int i = 2; i < n; ++i) a.push_back(rand_range(1, x));
    } else {
        for (int i = 0; i < n; ++i) a.push_back(rand_range(1, 1000000000LL));
    }
    
    for (int i = 0; i < n; ++i) {
        out << a[i] << (i == n-1 ? "\n" : " ");
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