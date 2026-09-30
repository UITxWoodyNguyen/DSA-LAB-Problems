#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void heapify(int a[], int n, int i) {
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

void BuildHeap(int a[], int n) {
    for(int i = (n >> 1) - 1; i >= 0; i--) heapify(a, n, i);
}

void HeapSort(int a[], int n) {
    BuildHeap(a, n);
    for(int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    HeapSort(a, n);

    XuatMang(a, n);

    return 0;
}
