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
    
    int n, q;
    if (test_id <= 5) {
        n = rand_range(1, 10);
        q = rand_range(1, 10);
    } else if (test_id <= 15) {
        n = rand_range(10, 1000);
        q = rand_range(10, 1000);
    } else if (test_id <= 30) {
        n = rand_range(1000, 100000);
        q = rand_range(1000, 50000);
    } else if (test_id <= 40) {
        n = 100000;
        q = 500000;
    } else {
        n = rand_range(50000, 100000);
        q = rand_range(50000, 500000);
    }
    
    out << n << " " << q << "\n";
    
    vector<long long> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(rand_range(-1000000000LL, 1000000000LL));
    }
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; ++i) {
        out << a[i] << (i == n-1 ? "\n" : " ");
    }
    
    for (int i = 0; i < q; ++i) {
        long long x;
        if (test_id <= 5) {
            x = a[rand_range(0, n-1)];
        } else if (test_id <= 10) {
            x = a[0] - rand_range(1, 100);
        } else if (test_id <= 15) {
            x = a.back() + rand_range(1, 100);
        } else {
            x = rand_range(-1000000000LL, 1000000000LL);
        }
        out << x << "\n";
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