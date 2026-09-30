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
    
    // Find position to insert using binary search (iterative, O(log n))
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= X) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int pos = left;
    
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