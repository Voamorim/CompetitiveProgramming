#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define endl '\n'
#define all(vet) (vet).begin, (vet).end()
#define MOD 1000000007


// Defines


// Variables
multiset<pii> ms;
int n;
vector<ll> dist;
// Functions
void dijkstra(int src, vector<vector<pii>> &adj){
    priority_queue<pair<ll, int>> pq;
    dist.assign(n, LLONG_MAX);
    vector<bool> done(n, false);
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().S;
        pq.pop();
        if(done[u]) continue;
        done[u] = true;

        for(auto e : adj[u]){
            int v = e.F;
            ll w = e.S;



            if(ms.find({u, v}) != ms.end() and ms.find({v, u}) != ms.end()){
                dist[v] = min(dist[u], dist[v]);
                pq.push({-dist[v], v});
            } else if(dist[u] + w < dist[v]){
                dist[v] = w + dist[u];
                pq.push({-dist[v], v});
            }
        }

    }

}


int main(){ _
    int  m;

    while(1){
        cin >> n >> m;
        if(not n and not m) return 0;

    vector<vector<pii>> adj(n);
    while(m--){
        int a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a].PB({b, c});
        ms.insert({a, b});
    }

    int k; cin >> k;

    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        dijkstra(a, adj);
        if(dist[b] == LLONG_MAX){
            cout << "Nao e possivel entregar a carta" << endl;
        } else {
            cout << dist[b] << endl;
        }
    }
    cout << endl;
    ms.clear();
    adj.clear();
    }
	return 0;
}
