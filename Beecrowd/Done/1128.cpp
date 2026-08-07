#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'

// Defines
#define MAXN 1001

// Variables
int n, m;


// Functions
void dfs(vector<vector<int>> &adj, vector<bool> &vis, int o){
	vis[o] = true;
	for(auto v : adj[o]){
		if(vis[v]) continue;
		dfs(adj, vis, v);
	}
}

/* Constroi o grafo normal e o grafo reverso para verificar se o grafo eh fortemente conexo
 Caso a DFS não passe por algum vertice do grafo reverso e passe pelo grafo normal, ele não é fortemente conexo
 Caso contrario, ele eh fortemente conexo */
int main(){ _
	while(1){
		cin >> n >> m; 

		vector<vector<int>> adj(n+1), rev(n+1);
		vector<bool> vis(n+1, 0), visr(n+1, 0);

		if(!n and !m) return 0;
		for(int i = 0; i < m; i++){
			int a, b, c; cin >> a >> b >> c;
			
			if(c == 1){
				adj[a].PB(b);
				rev[b].PB(a);
			} else {
				adj[a].PB(b);
				adj[b].PB(a);
				rev[a].PB(b);
				rev[b].PB(a);
			}
		}

		dfs(adj, vis, 1);
		dfs(rev, visr, 1);

		bool ans = true;

		for(int i = 1; i <= n; i++){
			if(vis[i] and visr[i]) continue;

			ans = false;
			break;
		}

		cout << (int) ans << endl;
	}
	return 0;
}
