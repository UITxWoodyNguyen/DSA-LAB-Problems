#include <bits/stdc++.h>
using namespace std;

void heapify(vector<long long>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) {
        cout << "0\n\n";
        return 0;
    }
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, n, i);
    }
    
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    
    return 0;
}