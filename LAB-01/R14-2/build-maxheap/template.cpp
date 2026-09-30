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


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    BuildHeap(a, n);

    XuatMang(a, n);

    return 0;
}
