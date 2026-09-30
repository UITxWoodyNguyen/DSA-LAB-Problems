#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <queue>

#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

bool isMaxHeap(int A[], int N) {
    for (int i = 0; i < N; ++i) {
        int childLeft = 2 * i + 1;
        int childRight = 2 * i + 2;
        if (childLeft < N && A[i] < A[childLeft]) {
            return false;
        }
        if (childRight < N && A[i] < A[childRight]) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    std::cout << (isMaxHeap(a, n) ? "true" : "false") << std::endl;
    return 0;
}