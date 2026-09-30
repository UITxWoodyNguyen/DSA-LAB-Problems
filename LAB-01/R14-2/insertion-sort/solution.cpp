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
    
    for (int i = 1; i < n; ++i) {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi xu ly: ";
        printArray(a);
        
        long long key = a[i];
        cout << "Phan tu dang xet A[" << i << "] = " << key << "\n";
        
        int j = i - 1;
        int k = i;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
            k = j + 1;
        }
        a[k] = key;
        
        cout << "Chen " << key << " vao vi tri k = " << k << "\n";
        cout << "Mang sau khi xu ly: ";
        printArray(a);
        cout << "\n";
    }
    
    cout << "Mang sau khi sap xep:\n";
    printArray(a);
    
    return 0;
}