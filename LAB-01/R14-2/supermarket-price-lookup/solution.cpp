#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<pair<long long, long long>> products(n);
    for (int i = 0; i < n; ++i) {
        cin >> products[i].first >> products[i].second;
    }
    
    long long query;
    cin >> query;
    
    int left = 0, right = n - 1;
    bool found = false;
    long long price = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (products[mid].first == query) {
            found = true;
            price = products[mid].second;
            break;
        } else if (products[mid].first < query) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (found) {
        cout << price << "\n";
    } else {
        cout << "Not Found\n";
    }
    return 0;
}