#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100010
#define f first
#define s second

struct Node {
    int max_val;
    int sol;
    int lmost;
};

int n;
vector<Node> segtree(MAXN * 4);
vector<int> buildings(MAXN);

int segtreeCount(int prev_max, int tl, int tr, int node) {
    if (tl == tr) {
        return segtree[node].max_val > prev_max;
    }

    int lcount = 0;
    int rcount = 0;

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    int lmax = segtree[lchild].max_val;
    int lsol = segtree[lchild].sol;
    int llmost = segtree[lchild].lmost;

    int rmax = segtree[rchild].max_val;
    int rsol = segtree[rchild].sol;
    int rlmost = segtree[rchild].lmost;

    if (prev_max < lmax) {
        if (llmost > prev_max) {
            lcount = lsol;
        } else {
            lcount = segtreeCount(prev_max, tl, tmid, lchild);
        }
        prev_max = lmax;
    }

    if (prev_max < rmax) {
        if (rlmost > prev_max) {
            rcount = rsol;
        } else {
            rcount = segtreeCount(prev_max, tmid + 1, tr, rchild);
        }
    }

    return lcount + rcount;
}

void segtreeBuild(int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        segtree[node] = {buildings[tl], 1, buildings[tl]};
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    segtreeBuild(tl, tmid, lchild);
    segtreeBuild(tmid + 1, tr, rchild);

    int lmax = segtree[lchild].max_val;
    int lsol = segtree[lchild].sol;
    int llmost = segtree[lchild].lmost;

    int rmax = segtree[rchild].max_val;
    int rsol = segtree[rchild].sol;
    int rlmost = segtree[rchild].lmost;

    if (lmax >= rmax) {
        segtree[node] = {lmax, lsol, llmost};
        return;
    }

    if (lmax < llmost) {
        segtree[node] = {rmax, lsol + rsol, llmost};
        return;
    }

    int sol = lsol + segtreeCount(lmax, tmid + 1, tr, rchild);

    segtree[node] = {rmax, sol, llmost};
}

pair<int, int> segtreeQuery(int l, int r, int tl = 0, int tr = n - 1, int node = 1,
                            int prev_max = -1) {
    if (tl > r || tr < l) return {0, -1};

    if (tl >= l && tr <= r) {
        if (segtree[node].max_val <= prev_max) return {0, -1};

        int sol = segtreeCount(prev_max, tl, tr, node);
        int new_max = segtree[node].max_val;

        return make_pair(sol, new_max);
    } else {
        int tmid = (tl + tr) / 2;
        int lchild = node * 2;
        int rchild = node * 2 + 1;

        auto [lsol, lmax] = segtreeQuery(l, r, tl, tmid, lchild, prev_max);

        prev_max = max(prev_max, lmax);

        auto [rsol, rmax] = segtreeQuery(l, r, tmid + 1, tr, rchild, prev_max);

        prev_max = max(prev_max, rmax);

        return make_pair(lsol + rsol, prev_max);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> n >> q) {
        for (int i = 0; i < n; ++i) cin >> buildings[i];

        segtreeBuild();

        while (q--) {
            int l, r;
            cin >> l >> r;
            l -= 1, r -= 1;

            cout << segtreeQuery(l, r).first << "\n";
        }
    }

    return 0;
}
