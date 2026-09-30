#include <iostream>
#include <string>
using namespace std;

const string notFound = "Not Found";
const int MAX_N = 2e6 + 36; 

struct Product {
    long long code;
    int price;
};
Product prods[MAX_N];
int n;
long long targetCode;
int indexResult;

void getPrice(const Product &p) {
    cout << p.price << endl;
}

int BinarySearchCode(long long code) {
    int lo = 0, hi = n - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (prods[mid].code == code) {
            ans = mid;
            hi = mid - 1;
        } else if (prods[mid].code < code) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> prods[i].code >> prods[i].price;
    }

    cin >> targetCode;

    indexResult = BinarySearchCode(targetCode);

    if (indexResult == -1) {
        cout << notFound << endl;
    } else {
        getPrice(prods[indexResult]);
    }

    return 0;
}