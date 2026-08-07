#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

#define MAXN 200020

int n, m;
vector<vector<int>> adj(MAXN);
vector<ll> dist(MAXN);
vector<int> par(MAXN);

void bfs(int o){
	queue<int> q;
	dist[o] = 0;
	q.push(o);

	while(!q.empty()){
		int w = q.front();
		q.pop();

		for(int x : adj[w]){
			if(dist[x] == -1){
				par[x] = w;
				dist[x] = dist[w] + 1;
				q.push(x);
			}
		}
	}
}

int main(){ _
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int o, d; cin >> o >> d;

		adj[o].push_back(d);
		adj[d].push_back(o);
	}

	memset(&dist[0], -1, sizeof(int) * MAXN);	
	memset(&par[0], -1, sizeof(int) * MAXN);

	bfs(1);

	if(dist[n] == -1){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	cout << dist[n] + 1 << endl;

	stack<int> p;
	p.push(n);
	int atual = n;
	while(par[atual] != -1){
		p.push(par[atual]);
		atual = par[atual];
	}
	while(!p.empty()){
		if(p.size() == 1) cout << p.top() << endl;
		else cout << p.top() << ' ';
		p.pop();
	}

	return 0;
}
