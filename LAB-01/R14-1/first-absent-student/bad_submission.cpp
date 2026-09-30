#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <future>
#include <atomic>
#include <condition_variable>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <functional>
#include <memory>
#include <utility>
#include <tuple>
#include <array>
#include <variant>
#include <optional>
#include <filesystem>
#include <regex>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    string name, status;
    for (int i = 0; i < n; ++i) {
        cin >> name >> status;
        if (status == "A") {
            cout << name << "\n";
            return 0;
        }
    }
    
    cout << "All Present\n";
    return 0;
}