#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define f first
#define s second

typedef long long ll;

#define MAXN 100010

int n, m;
vector<vector<pair<int, ll>>> adj(MAXN);
vector<bool> vis(MAXN);
vector<ll> dist(MAXN);
vector<int> par(MAXN);

void dijkstra(int o){
	priority_queue<pair<ll, int>> pq;
	dist.assign(n+1, LLONG_MAX);
	par.assign(n+1, -1);
	dist[o] = 0;
	pq.push({0, o});
	while(!pq.empty()){
		int u = pq.top().s;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto edge : adj[u]){
			int v = edge.f;
			ll w = edge.s;
			if(dist[u]+w < dist[v]){
				dist[v] = dist[u]+w;
				pq.push({-dist[v], v});
				par[v] = u;
			}
		}
	}
}	

int main(){ _
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int o, d; ll p; cin >> o >> d >> p;
		o--, d--;
		adj[o].pb({d, p});
	}
	dijkstra(0);
	for(int i = 0; i < n-1; i++) cout << dist[i] << ' ';
	cout << dist[n-1] << endl;


	return 0;
}
