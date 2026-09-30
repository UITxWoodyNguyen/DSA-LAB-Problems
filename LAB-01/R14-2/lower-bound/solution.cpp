#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; ++i) {
        long long x;
        cin >> x;
        
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end()) {
            cout << -1 << "\n";
        } else {
            cout << *it << "\n";
        }
    }
    
    return 0;
}