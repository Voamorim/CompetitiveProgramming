#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

#define MAXN 200010

int n, q; 
vector<ll> segtree(MAXN * 4);
vector<int> val (MAXN);
vector<ll> lazy (MAXN * 4);
vector<bool> has (MAXN * 4);

void segtreeBuild(int node, int l, int r){
    if(l == r){
        segtree[node] = val[l];
        return;
    } 

    int mid = (l + r) / 2;

    segtreeBuild(node * 2, l, mid);
    segtreeBuild(node * 2 + 1, mid + 1, r);

    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

void segtreePropagate(int node, int l, int r){
    if(not has[node]) return;

    segtree[node] += lazy[node] * (r - l + 1);

    // Caso ainda houverem filhos mais abaixo da arvore, passa a atualizacao 
    // restante para baixo
    if(l != r){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];

        has[node * 2] = true;
        has[node * 2 + 1] = true;
    }

    lazy[node] = 0;
    has[node] = false;
}

ll segtreeQuery(int node, int tl, int tr, int l, int r){
    segtreePropagate(node, tl, tr);

    if(l > tr or r < tl) return 0;
    if(l <= tl and r >= tr) return segtree[node];

    int mid = (tl + tr) / 2;

    return segtreeQuery(node * 2, tl, mid, l, r) 
           + segtreeQuery(node * 2 + 1, mid + 1, tr, l, r);
}

void segtreeUpdate(int node, int tl, int tr, int l, int r, int x){
    if(tr < l or r < tl) return;
    
    if(tl >= l and tr <= r){
        lazy[node] += x;
        has[node] = true;
        segtreePropagate(node, tl, tr);
        return;
    }

    int mid = (tl + tr) / 2;

    segtreeUpdate(node * 2, tl, mid, l, r, x);
    segtreeUpdate(node * 2 + 1, mid + 1, tr, l, r, x);

    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

signed main(){ _
    cin >> n >> q; 

    // Lê o vetor original
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    // Computa o array de diferencas
    val[0] = v[0];
    for(int i = 1; i < n; ++i)
        val[i] = v[i] - v[i-1];

    // Constroi a segtree a partir do vetor de diferencas
    segtreeBuild(1, 0, n-1);

    while(q--){
        int a, b, c, d; cin >> a >> b;

        if(a == 1){
            // Atualiza a diferenca no início do intervalo e uma posicao apos o
            // final do intervalo
            cin >> c >> d; b--, c--; 
            segtreeUpdate(1, 0, n-1, b, b, d);
            segtreeUpdate(1, 0, n-1, c+1, c+1, -d);
        } else {
            // Calcula e imprime o valor na posicao somando as diferencas 
            // acumuladas da primeira posicao até a posicao procurada
            b--;
            cout << segtreeQuery(1, 0, n-1, 0, b) << endl;
        }
    }
	return 0;
}
