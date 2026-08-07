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
int segtree[2 * MAXN];

void updateSegtree(int p, int x){
    p += n;
    segtree[p] = x;
    while(p >>= 1){
        segtree[p] = min(segtree[2* p], segtree[2*p + 1]);
    }
}

int querySegtree(int l, int r){
    l += n, r += n;

    int ans = INT_MAX;
    while(l < r){
        if(l & 1) ans = min(ans, segtree[l++]);
        if(r & 1) ans = min(ans, segtree[--r]);

        l >>= 1, r >>= 1;
    }
    return ans;
}

int main(){ _
    cin >> n >> q;

    // Lê os valores do array original
    for(int i = 0; i < n; ++i){
        cin >> segtree[i+n];
    }

    // Constrói a segtree atualizando os pais dos nós
    for(int i = n - 1; i > 0; --i){
        segtree[i] = min(segtree[i << 1], segtree[i << 1 | 1]);
    }

    while(q--){
        int l, r; cin >> l >> r;
        l--;
        
        cout << querySegtree(l, r) << endl;
    }

	return 0;
}
