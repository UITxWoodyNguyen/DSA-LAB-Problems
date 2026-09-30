#include <bits/stdc++.h>
using namespace std;

struct Student {
    long long id;
    string name;
    int score;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].id >> students[i].name >> students[i].score;
    }
    
    // Insertion sort
    for (int i = 1; i < n; ++i) {
        Student key = students[i];
        int j = i - 1;
        
        while (j >= 0) {
            // Compare: higher score first, then name ascending
            bool shouldMove = false;
            if (students[j].score < key.score) {
                shouldMove = true;
            } else if (students[j].score == key.score && students[j].name > key.name) {
                shouldMove = true;
            }
            
            if (shouldMove) {
                students[j + 1] = students[j];
                j--;
            } else {
                break;
            }
        }
        students[j + 1] = key;
    }
    
    for (const auto& s : students) {
        cout << s.id << " " << s.name << " " << s.score << "\n";
    }
    
    return 0;
}