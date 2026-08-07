#include <bits/stdc++.h>

using namespace std;

#define ELEM_NEUTRO 0
#define MAXN 200010

int n;
vector<int> values(MAXN);

int nnodes = 0;
int nroots = 0;
vector<int> segtree(4 * MAXN);
vector<int> roots(MAXN);
vector<int> L(MAXN);
vector<int> R(MAXN);

int merge(int lchild, int rchild) { return segtree[lchild] + segtree[rchild]; }

int cloneNode(int old_node) {
    int new_node = nnodes;
    nnodes += 1;

    L[new_node] = L[old_node];
    R[new_node] = R[old_node];
    segtree[new_node] = segtree[old_node];

    return new_node;
}

int segtreeBuild(int tl = 0, int tr = n - 1) {
    int curr_node = nnodes++;

    if (tl == tr) {
        segtree[curr_node] = values[tl];
        return curr_node;
    }

    int tmid = (tl + tr) / 2;

    L[curr_node] = segtreeBuild(tl, tmid);
    R[curr_node] = segtreeBuild(tmid + 1, tr);

    segtree[curr_node] = merge(L[curr_node], R[curr_node]);

    return curr_node;
}

int segtreeCopyArray(int k) {
    int new_root = nnodes;
    roots[nroots] = new_root;

    nnodes += 1;

    int old_root = roots[k];

    L[new_root] = L[old_root];
    R[new_root] = R[old_root];

    segtree[new_root] = segtree[old_root];

    return new_root;
}

int segtreeUpdate(int prev_node, int pos, int value, int tl = 0, int tr = n - 1) {
    if (tr < pos or tl > pos) return ELEM_NEUTRO;

    if (tl == pos and tr == pos) {
        segtree[
    }
}

void segtreeQuery();

int main() {
    int q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    roots[0] = segtreeBuild();
    nroots += 1;

    while (q--) {
        int mode;
        cin >> mode;

        if (mode == 1) {  // Altera o valor a no array k para x
            int a, k, x;
            cin >> k >> a >> x;

        } else if (mode == 2) {  // Soma no range [a,b] do array k
            int a, b, k;
            cin >> k >> a >> b;

        } else if (mode == 3) {  // Copia
            int k;
            cin >> k;
            k -= 1;
        }
    }
    return 0;
}
