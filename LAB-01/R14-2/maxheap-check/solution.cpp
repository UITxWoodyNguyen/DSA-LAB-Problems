#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) {
        cout << "true\n";
        return 0;
    }
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    bool isHeap = true;
    for (int i = 0; i < n; ++i) {
        int childLeft = 2 * i + 1;
        int childRight = 2 * i + 2;
        
        if (childLeft < n && a[i] < a[childLeft]) {
            isHeap = false;
            break;
        }
        if (childRight < n && a[i] < a[childRight]) {
            isHeap = false;
            break;
        }
    }
    
    cout << (isHeap ? "true" : "false") << "\n";
    return 0;
}