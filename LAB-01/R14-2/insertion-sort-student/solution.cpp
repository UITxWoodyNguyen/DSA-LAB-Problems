#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maso;
    string ten;
    int diem;
};

const int MAXN = 1e3 + 36;
SinhVien list[MAXN];

void insertionSort(SinhVien list[], int n) {
    for(int i = 1; i < n; i++) {
        SinhVien key = list[i];
        int lo = 0, hi = i - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (list[mid].diem == key.diem) {
                if (list[mid].ten > key.ten) hi = mid - 1;
                else lo = mid + 1;
            } else if (list[mid].diem > key.diem) lo = mid + 1;
            else hi = mid - 1;
        }

        for(int j = i - 1; j >= lo; j--) list[j + 1] = list[j];
        list[lo] = key;
    }
}


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
