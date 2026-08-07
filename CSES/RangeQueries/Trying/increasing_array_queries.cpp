#include <iostream>
#include <vector>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define MAXN 200010
#define ll long long

int n, q;
vector<int> values(MAXN);

struct Node {
    ll nop;
    int lval, rval;
};

vector<Node> segtree(MAXN * 4);

Node increaseSegtree(int min_val, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        if (segtree[node].lval >= min_val) {
            return {0, segtree[node].lval, segtree[node].lval};
        }

        ll num_ops = min_val - segtree[node].lval;
        return {num_ops, min_val, min_val};
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    ll nops = 0;

    auto [lnops, llval, lrval] = increaseSegtree(min_val, tl, tmid, lchild);

    min_val = lrval;

    auto [rnops, rlval, rrval] = increaseSegtree(min_val, tmid + 1, tr, rchild);

    nops = lnops + rnops;
    return {nops, llval, rrval};
}

Node buildSegtree(int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        segtree[node].nop = 0;
        segtree[node].lval = values[tl];
        segtree[node].rval = values[tl];
        return segtree[node];
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    auto [lnop, llval, lrval] = buildSegtree(tl, tmid, lchild);
    auto [rnop, rlval, rrval] = buildSegtree(tmid + 1, tr, rchild);

    if (lrval <= rlval) {
        segtree[node].nop = lnop + rnop;
        segtree[node].lval = llval;
        segtree[node].rval = rrval;
        return segtree[node];
    }

    // só precisamos atualizar o range da direita
    auto [extra_nops, new_lval, new_rval] = increaseSegtree(lrval, tmid + 1, tr, rchild);

    segtree[node].nop = lnop + rnop + extra_nops;
    segtree[node].lval = new_lval;
    segtree[node].rval = new_rval;

    return segtree[node];
}

Node segtreeQuery(int l, int r, int min_val = 0, int tl = 0, int tr = n - 1, int node = 1) {
    if (tr < l or tl > r) return {0, 0, 0};

    if (tl >= l and tr <= r) {
        if (segtree[node].lval >= min_val) {
            return segtree[node];
        }

        auto [extra_nops, new_lval, new_rval] = increaseSegtree(min_val, tl, tr, node);

        return {extra_nops + segtree[node].nop, new_lval, new_rval};
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    auto [lops, llval, lrval] = segtreeQuery(l, r, min_val, tl, tmid, lchild);
    auto [rops, rlval, rrval] = segtreeQuery(l, r, lrval, tmid + 1, tr, rchild);

    return {lops + rops, llval, rrval};
}

int main() {
    _ cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    buildSegtree();

    while (q--) {
        int a, b;
        cin >> a >> b;
        a -= 1, b -= 1;

        cout << segtreeQuery(a, b).nop << endl;
    }

    return 0;
}
