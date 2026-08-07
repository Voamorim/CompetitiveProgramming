#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define _               \
    ios_bas:            \
    sync_with_stdio(0); \
    cin.tie(0);

#define ll long long

#define MAXN 200010

int n, q;
vector<int> values(MAXN);

struct Pizzeria {
    ll min_left, min_right;
};

vector<Pizzeria> segtree(MAXN * 4, {INT_MAX, INT_MAX});

void segtreeBuild(int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        segtree[node].min_left = values[tl];
        segtree[node].min_right = values[tl];
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    segtreeBuild(tl, tmid, lchild);
    segtreeBuild(tmid + 1, tr, rchild);

    ll lc_left = segtree[lchild].min_left;
    ll rc_left = segtree[rchild].min_left;

    ll min_left = min(lc_left, rc_left + (tmid - tl + 1));
    segtree[node].min_left = min_left;

    ll lc_right = segtree[lchild].min_right;
    ll rc_right = segtree[rchild].min_right;

    ll min_right = min(rc_right, lc_right + (tr - tmid));
    segtree[node].min_right = min_right;

    return;
}

void segtreeUpdate(int pos, int value, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > pos or tr < pos) return;

    if (tl == pos and tr == pos) {
        segtree[node].min_left = value;
        segtree[node].min_right = value;
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    segtreeUpdate(pos, value, tl, tmid, lchild);
    segtreeUpdate(pos, value, tmid + 1, tr, rchild);

    ll lc_left = segtree[lchild].min_left;
    ll rc_left = segtree[rchild].min_left;

    ll min_left = min(lc_left, rc_left + (tmid - tl + 1));
    segtree[node].min_left = min_left;

    ll lc_right = segtree[lchild].min_right;
    ll rc_right = segtree[rchild].min_right;

    ll min_right = min(rc_right, lc_right + (tr - tmid));
    segtree[node].min_right = min_right;
}

ll segtreeQuery(int pos, int tl = 0, int tr = n - 1, int node = 1) {
    if (pos == tl) {
        return segtree[node].min_left;
    }
    if (pos == tr) {
        return segtree[node].min_right;
    }

    if (pos < tl) {
        return abs(pos - tl) + segtree[node].min_left;
    }
    if (pos > tr) {
        return abs(pos - tr) + segtree[node].min_right;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    ll lans = segtreeQuery(pos, tl, tmid, lchild);
    ll rans = segtreeQuery(pos, tmid + 1, tr, rchild);

    return min(lans, rans);
}

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; ++i) cin >> values[i];

    segtreeBuild();

    while (q--) {
        int mode;
        cin >> mode;

        if (mode == 1) {
            int building, new_price;
            cin >> building >> new_price;
            building -= 1;

            segtreeUpdate(building, new_price);
        } else if (mode == 2) {
            int building;
            cin >> building;
            building -= 1;

            cout << segtreeQuery(building) << endl;
        }
    }
    return 0;
}
