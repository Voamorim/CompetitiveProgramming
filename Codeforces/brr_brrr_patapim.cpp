#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define dbg(x) cout << #x << " == " << x << endl
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define F first
#define S second
#define PB push_back
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

int main() {
    _ int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(2 * n);

        set<int> s;
        for (int i = 1; i <= 2 * n; i++) s.insert(i);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x;
                cin >> x;
                if (i == 1 || j == n) {
                    p[i + j - 1] = x;

                    s.erase(x);
                }
            }
        }
        p[0] = *s.lower_bound(-2);

        for (int i = 0; i < 2 * n - 1; i++) cout << p[i] << ' ';
        cout << p[2 * n - 1] << endl;
    }

    return 0;
}
