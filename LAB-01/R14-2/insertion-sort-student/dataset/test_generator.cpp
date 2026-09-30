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
    int len = rand_range(3, 8);
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
        n = rand_range(10, 100);
    } else {
        n = rand_range(100, 1000);
    }
    
    out << n << "\n";
    
    vector<long long> ids;
    for (int i = 0; i < n; ++i) {
        ids.push_back(rand_range(1, 1000000000LL));
    }
    sort(ids.begin(), ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    while ((int)ids.size() < n) {
        ids.push_back(rand_range(1, 1000000000LL));
        sort(ids.begin(), ids.end());
        ids.erase(unique(ids.begin(), ids.end()), ids.end());
    }
    
    vector<string> names;
    for (int i = 0; i < n; ++i) {
        names.push_back(rand_name());
    }
    
    if (test_id <= 5) {
        vector<int> scores = {100, 90, 80, 70, 60};
        for (int i = 0; i < n; ++i) {
            out << ids[i] << " " << names[i] << " " << scores[i % scores.size()] << "\n";
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int score = rand_range(0, 100);
            out << ids[i] << " " << names[i] << " " << score << "\n";
        }
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