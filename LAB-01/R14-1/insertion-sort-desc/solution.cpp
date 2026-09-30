#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) {
        cout << "0\n\n";
        return 0;
    }
    
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Insertion Sort (descending)
    for (int i = 1; i < n; ++i) {
        long long key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
    return 0;
}