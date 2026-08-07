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
int segtree[MAXN * 2];

int segtreeQuery(int l, int r){
    l += n, r += n;

    int ans = 0;
    while(l < r){
        if(l & 1) ans ^= segtree[l++];
        if(r & 1) ans ^= segtree[--r];

        l >>= 1, r >>= 1;
    }
    return ans;
}

int main(){ _
    cin >> n >> q;

    // Lê os elementos do array original e salva na segtree 
    for(int i = 0; i < n; ++i){
        cin >> segtree[n + i];
    }

    // Constrói a segtree a partir do array original
    for(int i = n - 1; i > 0; --i){
        segtree[i] = segtree[i << 1] ^ segtree[i << 1 | 1]; 
    }

    while(q--){
        int l, r; cin >> l >> r;
        l--;

        cout << segtreeQuery(l, r) << endl;
    }

	return 0;
}
