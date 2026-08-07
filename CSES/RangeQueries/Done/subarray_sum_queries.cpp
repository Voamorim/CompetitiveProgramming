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

struct Node {
    ll otimal, total, max_left, max_right;
};

// {otimo, total, max_lado_esq, max_lado_dir}
vector<Node> segtree(MAXN * 4);

void segtreeBuild(int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        ll otimal = max(values[tl], 0);
        ll total = values[tl];
        ll max_left = values[tl];
        ll max_right = values[tl];

        segtree[node].otimal = otimal;
        segtree[node].total = total;
        segtree[node].max_left = max_left;
        segtree[node].max_right = max_right;
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    segtreeBuild(tl, tmid, lchild);
    segtreeBuild(tmid + 1, tr, rchild);

    auto& [lotimal, ltotal, lleft_max, lright_max] = segtree[lchild];
    auto& [rotimal, rtotal, rleft_max, rright_max] = segtree[rchild];

    ll total = ltotal + rtotal;
    ll left_max = max(ltotal, max(ltotal + rleft_max, lleft_max));
    ll right_max = max(rtotal, max(rtotal + lright_max, rright_max));

    ll otimal = max(total, max(left_max, right_max));
    otimal = max(otimal, max(lright_max + rleft_max, max(lright_max, rleft_max)));
    otimal = max(otimal, max(lotimal, rotimal));
    otimal = max(otimal, 0LL);

    segtree[node].otimal = otimal;
    segtree[node].total = total;
    segtree[node].max_left = left_max;
    segtree[node].max_right = right_max;
}

void segtreeUpdate(int value, int pos, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > pos or tr < pos) return;

    if (tl == pos and tr == pos) {
        ll otimal = max(value, 0);
        ll total = value;
        ll max_left = value;
        ll max_right = value;

        segtree[node].otimal = otimal;
        segtree[node].total = total;
        segtree[node].max_left = max_left;
        segtree[node].max_right = max_right;
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2, rchild = node * 2 + 1;

    segtreeUpdate(value, pos, tl, tmid, lchild);
    segtreeUpdate(value, pos, tmid + 1, tr, rchild);

    auto& [lotimal, ltotal, lleft_max, lright_max] = segtree[lchild];
    auto& [rotimal, rtotal, rleft_max, rright_max] = segtree[rchild];

    ll total = ltotal + rtotal;
    ll left_max = max(ltotal, max(ltotal + rleft_max, lleft_max));
    ll right_max = max(rtotal, max(rtotal + lright_max, rright_max));

    ll otimal = max(total, max(left_max, right_max));
    otimal = max(otimal, max(lright_max + rleft_max, max(lright_max, rleft_max)));
    otimal = max(otimal, max(lotimal, rotimal));
    otimal = max(otimal, 0LL);

    segtree[node].otimal = otimal;
    segtree[node].total = total;
    segtree[node].max_left = left_max;
    segtree[node].max_right = right_max;
}

int main() {
    _ cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    segtreeBuild();

    while (q--) {
        int k, x;
        cin >> k >> x;
        k -= 1;

        segtreeUpdate(x, k);
        cout << segtree[1].otimal << '\n';
    }

    return 0;
}
