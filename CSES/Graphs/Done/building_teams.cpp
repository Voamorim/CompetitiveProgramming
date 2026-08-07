#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

#define MAXN 100100

int n, m;
vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN);
vector<int> team(MAXN);

bool impossible;

void dfs(int o){
	vis[o] = true;
	for(auto x : adj[o]){
		if(vis[x]){
			if(team[o] == team[x]){
			       	impossible = true;
				return;
			}
			continue;
		} else {
			team[x] = !team[o];
			dfs(x);
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

	for(int i = 0; i < n; i++){
		dfs(i);
	}

	if(impossible){
	       	cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	for(int i = 1; i < n; i++){
		cout << team[i] + 1 << ' ';
	}
	cout << team[n] + 1 << endl;
		

        return 0;
}
