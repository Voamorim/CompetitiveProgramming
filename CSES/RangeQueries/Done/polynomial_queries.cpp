#include <iostream>
#include <vector>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define MAXN 200001
#define ll long long

int n, q;
vector<int> values(MAXN);

struct Lazy {
    int constant;
    int count;
};

vector<ll> segtree(MAXN * 4);
vector<Lazy> lazy(MAXN * 4);

ll sum(int tl, int tr) {
    tr -= tl;
    tr++;
    ll ans = (tr * ((ll)tr + 1)) / 2;
    return ans;
}

void segtreeBuild(int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        segtree[node] = values[tl];
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    segtreeBuild(tl, tmid, lchild);
    segtreeBuild(tmid + 1, tr, rchild);

    segtree[node] = segtree[lchild] + segtree[rchild];
}

void segtreePropagate(int tl, int tr, int node) {
    if (not lazy[node].count) return;

    ll const_update = (tr - tl + 1) * (ll)lazy[node].constant;
    ll arit_update = lazy[node].count * sum(tl, tr);

    segtree[node] += const_update + arit_update;

    if (tl != tr) {
        int lchild = node * 2, rchild = node * 2 + 1;

        int tmid = (tl + tr) / 2;

        lazy[lchild].constant += lazy[node].constant;
        lazy[rchild].constant += lazy[node].constant + (tmid - tl + 1) * lazy[node].count;

        lazy[lchild].count += lazy[node].count;
        lazy[rchild].count += lazy[node].count;
    }

    lazy[node].constant = 0, lazy[node].count = 0;
}

void segtreeUpdate(int l, int r, int tl = 0, int tr = n - 1, int node = 1) {
    segtreePropagate(tl, tr, node);

    if (l > tr or r < tl) return;

    if (tl >= l and tr <= r) {
        lazy[node].constant += tl - l;
        lazy[node].count += 1;

        segtreePropagate(tl, tr, node);
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    segtreeUpdate(l, r, tl, tmid, lchild);
    segtreeUpdate(l, r, tmid + 1, tr, rchild);

    segtree[node] = segtree[lchild] + segtree[rchild];
}

ll segtreeQuery(int l, int r, int tl = 0, int tr = n - 1, int node = 1) {
    segtreePropagate(tl, tr, node);

    if (l > tr or r < tl) return 0LL;
    if (tl >= l and tr <= r) {
        return segtree[node];
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = lchild + 1;

    return segtreeQuery(l, r, tl, tmid, lchild) + segtreeQuery(l, r, tmid + 1, tr, rchild);
}

int main() {
    _ cin >> n >> q;

    for (int i = 0; i < n; ++i) cin >> values[i];

    segtreeBuild();

    while (q--) {
        int mode;
        cin >> mode;

        if (mode == 1) {
            int a, b;
            cin >> a >> b;
            a -= 1, b -= 1;
            segtreeUpdate(a, b);
        } else if (mode == 2) {
            int a, b;
            cin >> a >> b;
            a -= 1, b -= 1;
            cout << segtreeQuery(a, b) << endl;
        }
    }

    return 0;
}
