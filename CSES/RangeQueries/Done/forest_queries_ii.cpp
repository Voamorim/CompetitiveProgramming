#include <iostream>
#include <vector>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define MAXN 1001

int n, q;
string forest[MAXN];

vector<vector<int>> segtree(4 * MAXN, vector<int>(4 * MAXN));

void childSegtreeBuild(int sup_seg, int row, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        segtree[sup_seg][node] = (forest[row][tl] == '*');
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    childSegtreeBuild(sup_seg, row, tl, tmid, lchild);
    childSegtreeBuild(sup_seg, row, tmid + 1, tr, rchild);

    segtree[sup_seg][node] = segtree[sup_seg][lchild] + segtree[sup_seg][rchild];
}

void superSegtreeBuild(int tl = 0, int tr = n - 1, int node = 1) {
    if (tl == tr) {
        childSegtreeBuild(node, tl);
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    superSegtreeBuild(tl, tmid, lchild);
    superSegtreeBuild(tmid + 1, tr, rchild);

    for (int i = 0; i < 4 * MAXN; ++i) {
        segtree[node][i] = segtree[lchild][i] + segtree[rchild][i];
    }
}

int segtreeQuery1d(int l, int r, int sup_seg, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > r or tr < l) return 0;

    if (tl >= l and tr <= r) {
        return segtree[sup_seg][node];
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    return segtreeQuery1d(l, r, sup_seg, tl, tmid, lchild) +
           segtreeQuery1d(l, r, sup_seg, tmid + 1, tr, rchild);
}

int segtreeQuery2d(int li, int ri, int lj, int rj, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > ri or tr < li) return 0;

    if (tl >= li and tr <= ri) {
        return segtreeQuery1d(lj, rj, node);
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    return segtreeQuery2d(li, ri, lj, rj, tl, tmid, lchild) +
           segtreeQuery2d(li, ri, lj, rj, tmid + 1, tr, rchild);
}

int segtreeUpdate1d(int pos, int sup_seg, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > pos or tr < pos) return 0;

    if (tl == pos and tr == pos) {
        int prev = segtree[sup_seg][node];
        segtree[sup_seg][node] = !prev;

        return segtree[sup_seg][node] - prev;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    int lc = segtreeUpdate1d(pos, sup_seg, tl, tmid, lchild);
    int rc = segtreeUpdate1d(pos, sup_seg, tmid + 1, tr, rchild);

    segtree[sup_seg][node] += lc + rc;
    return lc + rc;
}

// faz o merge somente no caminho onde ocorreu a atualizacao
void mergeUpdatesSegtree2d(int j, int pnode, int lchild, int rchild, int tl = 0, int tr = n - 1,
                           int node = 1) {
    segtree[pnode][node] = segtree[lchild][node] + segtree[rchild][node];

    if (tl == tr) return;

    int tmid = (tl + tr) / 2;

    if (j <= tmid)
        mergeUpdatesSegtree2d(j, pnode, lchild, rchild, tl, tmid, node * 2);
    else
        mergeUpdatesSegtree2d(j, pnode, lchild, rchild, tmid + 1, tr, node * 2 + 1);
}

void segtreeUpdate2d(int i, int j, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > i or tr < i) return;

    if (tl == i and tr == i) {
        segtreeUpdate1d(j, node);
        return;
    }

    int tmid = (tl + tr) / 2;
    int lchild = node * 2;
    int rchild = node * 2 + 1;

    segtreeUpdate2d(i, j, tl, tmid, lchild);
    segtreeUpdate2d(i, j, tmid + 1, tr, rchild);

    mergeUpdatesSegtree2d(j, node, lchild, rchild);

    return;
}

int main() {
    _ cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> forest[i];
    }

    superSegtreeBuild();

    while (q--) {
        int mode;
        cin >> mode;

        if (mode == 1) {
            int i, j;
            cin >> i >> j;
            i -= 1, j -= 1;

            segtreeUpdate2d(i, j);
        } else if (mode == 2) {
            int li, lj, ri, rj;
            cin >> li >> lj >> ri >> rj;
            li -= 1, lj -= 1, ri -= 1, rj -= 1;

            cout << segtreeQuery2d(li, ri, lj, rj) << endl;
        }
    }

    return 0;
}
