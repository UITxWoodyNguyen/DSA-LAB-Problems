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
        n = test_id;
    } else if (test_id <= 15) {
        n = rand_range(5, 50);
    } else if (test_id <= 30) {
        n = rand_range(50, 100);
    } else {
        n = rand_range(100, 199);
    }
    
    out << n << "\n";
    
    vector<long long> a;
    if (test_id == 1) {
        for (int i = 0; i < n; ++i) a.push_back(i);
    } else if (test_id == 2) {
        for (int i = 0; i < n; ++i) a.push_back(n - i);
    } else if (test_id == 3) {
        for (int i = 0; i < n; ++i) a.push_back(42);
    } else {
        for (int i = 0; i < n; ++i) a.push_back(rand_range(-2000000000LL, 2000000000LL));
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