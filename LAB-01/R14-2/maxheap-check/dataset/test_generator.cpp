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

bool is_max_heap(const vector<long long>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && a[i] < a[left]) return false;
        if (right < n && a[i] < a[right]) return false;
    }
    return true;
}

vector<long long> make_max_heap(vector<long long> a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        int idx = i;
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;
            if (left < n && a[left] > a[largest]) largest = left;
            if (right < n && a[right] > a[largest]) largest = right;
            if (largest != idx) {
                swap(a[idx], a[largest]);
                idx = largest;
            } else break;
        }
    }
    return a;
}

void make_test(int test_id, const string &filepath) {
    ofstream out(filepath);
    
    int n;
    if (test_id == 1) {
        n = 0;
    } else if (test_id <= 5) {
        n = rand_range(1, 10);
    } else if (test_id <= 15) {
        n = rand_range(10, 100);
    } else if (test_id <= 30) {
        n = rand_range(100, 1000);
    } else {
        n = rand_range(1000, 10000);
    }
    
    out << n << "\n";
    
    if (n == 0) {
        out.close();
        return;
    }
    
    vector<long long> a;
    if (test_id <= 10) {
        a = make_max_heap(vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            a[i] = rand_range(1, 1000);
        }
        a = make_max_heap(a);
    } else if (test_id <= 20) {
        for (int i = 0; i < n; ++i) {
            a.push_back(rand_range(1, 1000000));
        }
    } else {
        a = make_max_heap(vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            a[i] = rand_range(1, 1000000);
        }
        a = make_max_heap(a);
        if (n >= 2) {
            swap(a[0], a[1]);
        }
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