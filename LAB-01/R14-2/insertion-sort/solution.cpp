#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<long long>& a) {
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

void insertionSort(vector<long long>& a) {
    int N = a.size();
    for(int i = 1; i < N; i++) {
        long long key = a[i];
        int j = i - 1;

        if (i > 1) cout << endl << "i = " << i << endl;
        else cout << "i = " << i << endl;

        cout << "Mang truoc khi xu ly: ";
        printArray(a);

        cout << "Phan tu dang xet A[" << i << "] = " << key << endl;

        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        cout << "Chen " << key << " vao vi tri k = " << j + 1 << endl;
        cout << "Mang sau khi xu ly: ";
        printArray(a);
        // cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << "Mang truoc khi sap xep:" << endl;
    printArray(A);
    cout << endl;

    cout << endl << "Sap xep:" << endl;
    insertionSort(A);

    cout << endl << "Mang sau khi sap xep:" << endl;
    printArray(A);

    return 0;
}