#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maso;
    string ten;
    int diem;
};

// YOUR CODE GOES HERE


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SinhVien* a = new SinhVien[n];
    for (int i = 0; i < n; i++) cin >> a[i].maso >> a[i].ten >> a[i].diem;

    insertionSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i].maso << ' ' << a[i].ten << ' ' << a[i].diem << '\n';
    }
    return 0;
}
