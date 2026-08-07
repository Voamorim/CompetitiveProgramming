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
        int n, m, l, r;

        cin >> n >> m >> l >> r;

        if (n == m) {
            cout << l << ' ' << r << endl;
            continue;
        }

        int dif = n - m;

        if (r >= dif) {
            r -= dif;
            cout << l << ' ' << r << endl;
            continue;
        }

        if (abs(l) >= dif) {
            l += dif;
            cout << l << ' ' << r << endl;
            continue;
        }

        dif -= r;
        r = 0;

        int x = l;
        l += dif;
        dif = 0;

        cout << l << ' ' << r << endl;
    }

    return 0;
}
