#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MAXN 200010

// Estratégia:
//      (1) Ordenar as queries pelo seu fim em ordem crescente
//      (2) Percorrer o vetor e salvar 1 nas posições da última ocorrência de cada
//          elemento. (substitui a ocorrência anterior por 0, se existir)
//      (3) A resposta para cada uma das queries é a soma total no intervalo [l, r]

int n, q;
vector<int> values(MAXN);

vector<int> segtree(MAXN * 4);

void segtreeUpdate(int pos, int val, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > pos or tr < pos) return;

    if (tl == pos && tr == pos) {
        segtree[node] += val;
        return;
    }

    int tmid = (tl + tr) / 2;

    segtreeUpdate(pos, val, tl, tmid, node * 2);
    segtreeUpdate(pos, val, tmid + 1, tr, node * 2 + 1);

    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];

    return;
}

int segtreeQuery(int l, int r, int tl = 0, int tr = n - 1, int node = 1) {
    if (tl > r or tr < l) return 0;

    if (tl >= l and tr <= r) {
        return segtree[node];
    }

    int tmid = (tl + tr) / 2;

    return segtreeQuery(l, r, tl, tmid, node * 2) + segtreeQuery(l, r, tmid + 1, tr, node * 2 + 1);
}

int main() {
    _ cin >> n >> q;

    for (int i = 0; i < n; ++i) cin >> values[i];

    vector<tuple<int, int, int>> queries;
    queries.reserve(q);

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a -= 1, b -= 1;

        queries.push_back(make_tuple(b, a, i));
    }

    sort(queries.begin(), queries.end());

    map<int, int> last_occurrence;
    vector<int> answers(MAXN);

    int i = 0;
    for (auto& [r, l, j] : queries) {
        for (; i <= r; ++i) {
            int val = values[i];

            if (last_occurrence.find(val) != last_occurrence.end()) {
                segtreeUpdate(last_occurrence[val], -1);
            }

            last_occurrence[val] = i;
            segtreeUpdate(i, 1);
        }

        answers[j] = segtreeQuery(l, r);
    }

    for (int i = 0; i < q; ++i) {
        cout << answers[i] << endl;
    }

    return 0;
}
