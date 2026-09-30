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
        n = rand_range(1, 10);
    } else if (test_id <= 15) {
        n = rand_range(10, 1000);
    } else if (test_id <= 30) {
        n = rand_range(1000, 10000);
    } else if (test_id <= 45) {
        n = rand_range(10000, 100000);
    } else {
        n = rand_range(100000, 500000);
    }
    
    out << n << "\n";
    
    vector<long long> codes(n);
    long long current = 1;
    for (int i = 0; i < n; ++i) {
        current += rand_range(1, 1000);
        codes[i] = current;
    }
    
    for (int i = 0; i < n; ++i) {
        long long price = rand_range(1, 1000000);
        out << codes[i] << " " << price << "\n";
    }
    
    long long query;
    if (test_id <= 5) {
        query = codes[rand_range(0, n-1)];
    } else if (test_id <= 10) {
        query = rand_range(1, 1000000000LL);
    } else if (test_id <= 15) {
        query = codes[0] - 1;
    } else if (test_id <= 20) {
        query = codes.back() + 1;
    } else {
        query = rand_range(1, 1000000000LL);
    }
    out << query << "\n";
    
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