#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long X;
    int n;
    if (!(cin >> X)) return 0;
    if (!(cin >> n)) {
        cout << X << "\n";
        return 0;
    }
    
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Find position to insert using linear search (O(n) with minimum comparisons)
    // For ascending sorted array, find first element > X
    int pos = n;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > X) {
            pos = i;
            break;
        }
    }
    
    // Output array with X inserted
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (i == pos) {
            if (!first) cout << " ";
            cout << X;
            first = false;
        }
        if (!first) cout << " ";
        cout << arr[i];
        first = false;
    }
    
    // If X is inserted at the end
    if (pos == n) {
        if (!first) cout << " ";
        cout << X;
    }
    
    cout << "\n";
    return 0;
}