#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) {
        cout << "false\n";
        return 0;
    }
    
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Selection Sort (ascending)
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
    
    // Check if sorted
    bool sorted = true;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            sorted = false;
            break;
        }
    }
    
    cout << (sorted ? "true" : "false") << "\n";
    return 0;
}