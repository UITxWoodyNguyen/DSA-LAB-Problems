#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <random>
#include <chrono>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>

namespace fs = std::filesystem;
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_range(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

string rand_name() {
    static const string consonants = "bcdfghjklmnpqrstvwxyz";
    static const string vowels = "aeiou";
    int len = rand_range(3, 10);
    string name;
    bool use_consonant = true;
    for (int i = 0; i < len; ++i) {
        if (use_consonant) {
            name += consonants[rand_range(0, consonants.size() - 1)];
            use_consonant = false;
        } else {
            name += vowels[rand_range(0, vowels.size() - 1)];
            use_consonant = true;
        }
    }
    name[0] = toupper(name[0]);
    return name;
}

void make_test(int test_id, const string &filepath) {
    ofstream out(filepath);
    
    int n;
    if (test_id <= 5) {
        n = rand_range(1, 10);
    } else if (test_id <= 15) {
        n = rand_range(10, 1000);
    } else if (test_id <= 30) {
        n = rand_range(1000, 100000);
    } else {
        n = rand_range(100000, 1000000);
    }
    
    out << n << "\n";
    
    vector<string> names;
    vector<char> statuses;
    
    for (int i = 0; i < n; ++i) {
        names.push_back(rand_name());
    }
    
    // Ensure at least one 'A' for most tests
    bool has_absent = false;
    if (test_id <= 5) {
        // First test: ensure first few have 'A'
        for (int i = 0; i < n; ++i) {
            if (i < 2 && rand_range(0, 1)) {
                statuses.push_back('A');
                has_absent = true;
            } else {
                statuses.push_back('P');
            }
        }
    } else if (test_id <= 10) {
        // Mix
        for (int i = 0; i < n; ++i) {
            statuses.push_back(rand_range(0, 1) ? 'A' : 'P');
        }
    } else if (test_id <= 20) {
        // All present
        for (int i = 0; i < n; ++i) {
            statuses.push_back('P');
        }
    } else if (test_id <= 30) {
        // All absent
        for (int i = 0; i < n; ++i) {
            statuses.push_back('A');
        }
    } else {
        // Random
        for (int i = 0; i < n; ++i) {
            statuses.push_back(rand_range(0, 1) ? 'A' : 'P');
        }
    }
    
    // Ensure at least one test has no absent
    if (test_id == 5) {
        fill(statuses.begin(), statuses.end(), 'P');
    }
    
    for (int i = 0; i < n; ++i) {
        out << names[i] << " " << statuses[i] << "\n";
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