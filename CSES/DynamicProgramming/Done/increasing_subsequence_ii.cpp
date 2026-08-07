#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define MOD 1000000007

int n;
vector<int> segtree(MAXN * 4);

void segtreeUpdate(int l, int r, int val, int tl = 0, int tr = n - 1, int node = 1) {
    if (tr < l or tl > r) return;

    if (tl >= l and tr <= r) {
        segtree[node] = (segtree[node] + val) % MOD;
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    segtreeUpdate(l, r, val, tl, tmid, lchild);
    segtreeUpdate(l, r, val, tmid + 1, tr, rchild);

    segtree[node] = (segtree[rchild] + segtree[lchild]) % MOD;
}

int segtreeQuery(int l, int r, int tl = 0, int tr = n - 1, int node = 1) {
    if (tr < l or tl > r) return 0;
    if (tl >= l and tr <= r) {
        return segtree[node];
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    return (segtreeQuery(l, r, tl, tmid, lchild) + segtreeQuery(l, r, tmid + 1, tr, rchild)) % MOD;
}

int main() {
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[i] = make_pair(x, i);
    }
    sort(v.begin(), v.end());

    vector<int> values(n);
    int val = 0;
    values[v[0].second] = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i].first != v[i - 1].first) val++;
        values[v[i].second] = val;
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int x = values[i];

        int curr = 1;
        if (x - 1 >= 0) {
            int q = segtreeQuery(0, x - 1);
            curr = (1 + q) % MOD;
        }

        segtreeUpdate(x, x, curr);

        ans = (ans + curr) % MOD;
    }

    cout << ans << endl;

    return 0;
}
