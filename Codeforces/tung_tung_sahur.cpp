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

const char l = 'L';
const char r = 'R';

int main() {
    _ int t;
    cin >> t;

    while (t--) {
        string p, s;
        cin >> p;
        cin >> s;

        int cl = 0, cr = 0;

        int j = 0;
        bool ans = true;

        for (int i = 0; i < p.size(); i++) {
            if (j >= s.size()) {
                ans = false;
                break;
            }

            char pp = p[i];
            char ss = s[j];

            if (pp == ss) {
                j++;

                if (pp == l) {
                    cl += 1;
                    cr = 0;
                } else {
                    cr += 1;
                    cl = 0;
                }
                continue;
            }

            if (pp != ss) {
                if (ss == l) {
                    while (ss == l) {
                        j++;
                        cl--;

                        if (cl < 0) ans = false;
                        if (j >= s.size()) ans = false;

                        if (not ans) break;

                        ss = s[j];
                    }
                } else {
                    while (ss == r) {
                        j++;
                        cr--;

                        if (cr < 0) ans = false;
                        if (j > s.size()) ans = false;

                        if (not ans) break;

                        ss = s[j];
                    }
                }
                i--;
            }
        }
        while (j < s.size()) {
            if (cr and s[j] == r) {
                cr--;
                j++;
            } else if (cl and s[j] == l) {
                cl--;
                j++;
            } else {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
