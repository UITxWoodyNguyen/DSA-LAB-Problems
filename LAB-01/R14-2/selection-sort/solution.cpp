#include <bits/stdc++.h>
using namespace std;

void printArray(const vector<long long>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << "Mang truoc khi sap xep:\n";
    printArray(a);
    cout << "\nSap xep:\n";
    
    for (int i = 0; i < n - 1; ++i) {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi swap: ";
        printArray(a);
        
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[max_idx]) {
                max_idx = j;
            }
        }
        
        cout << "Phan tu lon nhat trong doan [" << i+1 << ", " << n-1 << "]: " << a[max_idx] << "\n";
        cout << "Swap " << a[i] << " va " << a[max_idx] << "\n";
        swap(a[i], a[max_idx]);
        
        cout << "Mang sau khi swap: ";
        printArray(a);
        cout << "\n";
    }
    
    cout << "Mang sau khi sap xep:\n";
    printArray(a);
    
    return 0;
}