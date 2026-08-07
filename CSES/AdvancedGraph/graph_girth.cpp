#include <bits/stdc++.h>

using namespace std;

#define MAXN 2510

vector<vector<int>> graph(MAXN);

int ans;
int n;

void bfs(int src){
	queue<int> q;

	vector<int> dist(n, 0);
	vector<int> par(n, -1);

	dist[src] = 1;
	q.push(src);

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(auto & u : graph[v]){
			if(dist[u] and par[v] != u){
				int cycle_len = dist[u] - 1 + dist[v] - 1 + 1;
				ans = min(ans, cycle_len);	
				continue;
			} 
            if(dist[u]) continue;
			q.push(u);
			dist[u] = dist[v] + 1;
			par[u] = v;
		}
	}
}

int main(){
	int m; cin >> n >> m;

	ans = INT_MAX;

	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		a -= 1; b -= 1;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 0; i < n; ++i){
		bfs(i);			
	}

	if(ans == INT_MAX){
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;

	return 0;
}
