#include <bits/stdc++.h>
using namespace std;

// Iterative binary search (non-recursive)
bool binary_search_iterative(const vector<long long>& arr, long long target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) right = mid - 1;  // descending order
        else left = mid + 1;
    }
    return false;
}

// Recursive binary search
bool binary_search_recursive(const vector<long long>& arr, long long target, int left, int right) {
    if (left > right) return false;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return true;
    else if (arr[mid] < target) return binary_search_recursive(arr, target, left, mid - 1);
    else return binary_search_recursive(arr, target, mid + 1, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long X;
    int n;
    if (!(cin >> X)) return 0;
    if (!(cin >> n)) {
        cout << "false\n";
        return 0;
    }
    
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Use iterative version (or recursive - both implemented)
    bool found = binary_search_iterative(arr, X);
    // bool found = binary_search_recursive(arr, X, 0, n - 1);
    
    cout << (found ? "true" : "false") << "\n";
    return 0;
}