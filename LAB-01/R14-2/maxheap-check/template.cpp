#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    std::cout << "MaxHeap: " << std::boolalpha << isMaxHeap(a, n) << std::endl;

    return 0;
}
