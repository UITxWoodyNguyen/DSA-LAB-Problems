#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 36;
long long a[MAXN];

void heapify(long long a[], int n, int i) {
    int largest = i;
    int left = (i << 1) + 1;
    int right = (i << 1) + 2;

    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void BuildHeap(long long a[], int n) {
    for(int i = (n >> 1) - 1; i >= 0; i--) heapify(a, n, i);
}

void HeapSort(long long a[], int n) {
    BuildHeap(a, n);
    for(int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int binarySearch (long long a[], int n, int l, int r, long long x) {
    int res = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] == x) return mid;
        if (a[mid] < x) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return res;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];

    HeapSort(a, n);

    long long res = -1;
    for(int i = 0; i < n; i++) {
        long long target = x - a[i];
        int index = binarySearch(a, n, i + 1, n - 1, target);

        // cout << a[i] << " " << (index != -1 ? a[index] : 0) << endl;

        long long cur = a[i] + (index != -1 ? a[index] : 0);
        if (cur <= x) res = max(res, cur); 
    }
    cout << res << endl;
}