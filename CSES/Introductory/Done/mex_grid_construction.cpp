#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<set<int>> rows(n);
    vector<set<int>> columns(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            rows[i].insert(j);
            columns[i].insert(j);
        }
    }

    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int mr = *rows[i].begin();
            auto itc = columns[j].lower_bound(mr);

            while (*itc != mr) {
                mr = *rows[i].lower_bound(*itc);
                itc = columns[j].lower_bound(mr);
            }

            matrix[i][j] = mr;

            rows[i].erase(mr);
            columns[j].erase(mr);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
