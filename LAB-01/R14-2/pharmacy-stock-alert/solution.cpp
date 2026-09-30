#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Stock {
    string name;
    int quantity;
};

int linear_search_minimum (vector<Stock> &st, int n) {
    int min_index = 0;
    for(int i = 1; i < n; i++) {
        if (st[i].quantity < st[min_index].quantity) min_index = i;
    }
    return min_index;
}

void getName (Stock &s) {
    cout << s.name << endl;
}

int main () {
    int n;
    cin >> n;
    vector<Stock> st;
    for(int i = 0; i < n; i++) {
        Stock s;
        cin >> s.name >> s.quantity;
        st.push_back(s);
    }

    int min_index = linear_search_minimum(st, n);
    getName(st[min_index]);
}