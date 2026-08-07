#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define f first
#define s second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

#define MAXN 200010

int n, m;
vector<int> v(MAXN);
vector<pii> segtree(MAXN * 4);

void segtreeBuild(int node, int l, int r){
    if(l == r){
        segtree[node] = make_pair(v[l], l + 1);
    } else {
        int mid = (l + r) / 2;

        segtreeBuild(node * 2, l, mid);
        segtreeBuild(node * 2 + 1, mid + 1, r);

        if(segtree[2 * node].f >= segtree[2 * node + 1].f){
            segtree[node] = segtree[2 * node];
        } else {
            segtree[node] = segtree[2 * node + 1];
        }
    }
}

int segtreeQuery(int node, int tl, int tr, int l, int r, int x){
    if(l > tr or r < tl) return -INT_MAX;

    if(tl == tr){
        if(segtree[node].f >= x){
            segtree[node].f -= x;
            return segtree[node].s;
        }
        else return -INT_MAX;
    } 

    if(segtree[node].f < x) return -INT_MAX;

    int tm = (tl + tr) / 2;

    int ans = segtreeQuery(node*2, tl, tm, l, r, x);
    if(ans != -INT_MAX) {
        if(segtree[2 * node].f >= segtree[2 * node + 1].f){
            segtree[node] = segtree[2 * node];
        } else {
            segtree[node] = segtree[2 * node + 1];
        }
        return ans;
    }

    ans = segtreeQuery(node * 2 + 1, tm + 1, tr, l, r, x);
    if(ans != -INT_MAX){
        if(segtree[2 * node].f >= segtree[2 * node + 1].f){
            segtree[node] = segtree[2 * node];
        } else {
            segtree[node] = segtree[2 * node + 1];
        }
    }
    return ans;
}



int main(){ _
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    segtreeBuild(1, 0, n-1);

    while(m--){
        int g; cin >> g; 

        int ans;
        cout << ((ans = segtreeQuery(1, 0, n-1, 0, n-1, g)) == -INT_MAX ? 0 : ans) << (m == 0 ? '\n' : ' ');
    }

	return 0;
}
