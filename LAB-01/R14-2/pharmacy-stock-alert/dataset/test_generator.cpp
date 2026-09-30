#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <random>
#include <chrono>
#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_range(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

string rand_name(int len) {
    static const string consonants = "bcdfghjklmnpqrstvwxyz";
    static const string vowels = "aeiou";
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
        n = test_id;
    } else if (test_id <= 15) {
        n = rand_range(10, 100);
    } else if (test_id <= 30) {
        n = rand_range(100, 10000);
    } else if (test_id <= 45) {
        n = rand_range(10000, 100000);
    } else {
        n = rand_range(100000, 1000000);
    }
    
    out << n << "\n";
    
    vector<string> names;
    vector<int> stocks;
    
    for (int i = 0; i < n; ++i) {
        string name = rand_name(rand_range(5, 12));
        int stock = rand_range(1, 1000000);
        names.push_back(name);
        stocks.push_back(stock);
    }
    
    if (test_id == 1) {
        stocks[0] = 1;
    }
    if (test_id == 2) {
        for (int i = 0; i < n; ++i) stocks[i] = 100;
    }
    
    for (int i = 0; i < n; ++i) {
        out << names[i] << " " << stocks[i] << "\n";
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