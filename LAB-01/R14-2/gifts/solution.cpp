#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long best = 0;
    int left = 0, right = n - 1;
    
    while (left < right) {
        long long sum = a[left] + a[right];
        if (sum <= x) {
            best = max(best, sum);
            left++;
        } else {
            right--;
        }
    }
    
    cout << best << "\n";
    return 0;
}