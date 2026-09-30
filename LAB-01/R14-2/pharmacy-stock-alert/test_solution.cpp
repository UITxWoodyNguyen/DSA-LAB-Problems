#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    string min_name;
    int min_stock = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        string name;
        int stock;
        cin >> name >> stock;
        if (stock < min_stock) {
            min_stock = stock;
            min_name = name;
        }
    }
    
    cout << min_name << "\n";
    return 0;
}