#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distributeScholarships(vector<int>& students, int budget) {
    sort(students.begin(), students.end());

    int selected = 0;

    for (int amount : students) {
        if (budget >= amount) {
            budget -= amount;
            selected++;
        } else {
            break;
        }
    }

    return selected;
}

int main() {
    int n, budget;
    cin >> n >> budget;

    vector<int> students(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    cout << distributeScholarships(students, budget);

    return 0;
}