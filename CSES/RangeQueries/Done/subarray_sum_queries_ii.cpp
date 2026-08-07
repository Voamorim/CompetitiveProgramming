#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

#define ELEM_NEUTRO {0LL, 0LL, 0LL, 0LL}
#define MAXN 200010
#define ll long long

int n, q;
vector<int> values(MAXN);

struct Node {
    ll otimal, total, lmax, rmax;
};

vector<Node> segtree(MAXN * 4);

void segtreeBuild(int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        ll otimal = max(values[tl], 0);
        ll total = values[tl];
        ll lmax = values[tl];
        ll rmax = values[tl];

        segtree[node].otimal = otimal;
        segtree[node].total = total;
        segtree[node].lmax = lmax;
        segtree[node].rmax = rmax;

        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    segtreeBuild(tl, tmid, lchild);
    segtreeBuild(tmid + 1, tr, rchild);

    auto& [lotimal, ltotal, llmax, lrmax] = segtree[lchild];
    auto& [rotimal, rtotal, rlmax, rrmax] = segtree[rchild];

    ll otimal = max(lotimal, rotimal);
    otimal = max(otimal, lrmax + rlmax);

    ll total = ltotal + rtotal;
    otimal = max(otimal, total);

    ll lmax = max(ltotal, max(llmax, ltotal + rlmax));
    ll rmax = max(rtotal, max(rrmax, rtotal + lrmax));
    otimal = max(otimal, max(lmax, rmax));

    segtree[node].otimal = otimal;
    segtree[node].total = total;
    segtree[node].lmax = lmax;
    segtree[node].rmax = rmax;
}

Node segtreeQuery(int l, int r, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > r or tr < l) return ELEM_NEUTRO;

    if (tl >= l and tr <= r) {
        return segtree[node];
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    auto [lotimal, ltotal, llmax, lrmax] = segtreeQuery(l, r, tl, tmid, lchild);
    auto [rotimal, rtotal, rlmax, rrmax] = segtreeQuery(l, r, tmid + 1, tr, rchild);

    ll otimal = max(lotimal, rotimal);
    otimal = max(otimal, lrmax + rlmax);

    ll total = ltotal + rtotal;
    otimal = max(otimal, total);

    ll lmax = max(ltotal, max(llmax, ltotal + rlmax));
    ll rmax = max(rtotal, max(rrmax, rtotal + lrmax));
    otimal = max(otimal, max(lmax, rmax));

    Node ans;
    ans.otimal = otimal;
    ans.total = total;
    ans.lmax = lmax;
    ans.rmax = rmax;

    return ans;
}

int main() {
    _ cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    segtreeBuild();

    while (q--) {
        int a, b;
        cin >> a >> b;
        a -= 1, b -= 1;

        Node ans = segtreeQuery(a, b);
        cout << ans.otimal << endl;
    }
}
