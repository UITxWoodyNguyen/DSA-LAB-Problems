#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, k, b, m, n;
    if (!(cin >> a >> k >> b >> m >> n)) return 0;
    
    // Binary search for the answer
    // Check function: can we cut n trees in 'days' days?
    auto can_cut = [&](long long days) -> bool {
        long long work_days_a = days - days / k;
        long long work_days_b = days - days / m;
        
        // Check overflow: use __int128
        __int128 trees_a = (__int128)a * work_days_a;
        __int128 trees_b = (__int128)b * work_days_b;
        
        return (trees_a + trees_b) >= n;
    };
    
    long long left = 1, right = n + 1;  // upper bound: n days if a=b=1
    // Or use a tighter upper bound
    if (a > 0 && b > 0) {
        right = min(right, n / min(a, b) + 2);
    }
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (can_cut(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << "\n";
    return 0;
}