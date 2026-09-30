#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 36;
int a[MAX_N];
int n, q;

int lowerBound(int x) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    while (q--) {
        int x;
        cin >> x;
        int idx = lowerBound(x);
        if (idx < n) {
            cout << a[idx] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}