#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<long long>& a) {
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
}

void selectionSortDesc(vector<long long>& A) {
    int N = A.size();
    for (int i = 0; i < N - 1; i++) {
        if (i > 0) cout << endl << "i = " << i << endl;
        else cout << "i = " << i << endl;

        cout << "Mang truoc khi swap: ";
        printArray(A);
        cout << endl;

        int maxIdx = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] > A[maxIdx]) {
                maxIdx = j;
            }
        }

        cout << "Phan tu lon nhat trong doan [" << i + 1 << ", " << N - 1 << "]: " << A[maxIdx] << endl;
        cout << "Swap " << A[i] << " va " << A[maxIdx] << endl;

        swap(A[i], A[maxIdx]);

        cout << "Mang sau khi swap: ";
        printArray(A);
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << "Mang truoc khi sap xep:" << endl;
    printArray(A);
    cout << endl;

    cout << endl << "Sap xep:" << endl;
    selectionSortDesc(A);

    cout << endl << "Mang sau khi sap xep:" << endl;
    printArray(A);

    return 0;
}