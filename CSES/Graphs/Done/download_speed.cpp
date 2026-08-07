#include <bits/stdc++.h>

using namespace std;

#define INF LLONG_MAX 

int n, m;
vector<vector<long long>> capacity;
vector<vector<int>> adj;

long long bfs(int s, int t, vector<int> &parent){
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, long long>> q;
	q.push(make_pair(s, INF));

	while(!q.empty()){
		auto [curr, flow] = q.front();	
		q.pop();

		for(int next : adj[curr]){
			if(parent[next] == -1 && capacity[curr][next]){
				parent[next] = curr;
				long long new_flow = min(flow, capacity[curr][next]);
				if(next == t)
					return new_flow;
				q.push(make_pair(next, new_flow));
			}
		}
	}
	return 0;
}

long long maxFlow(int s, int t){
	long long flow = 0;
	vector<int> parent(n);
	long long new_flow;

	while(new_flow = bfs(s, t, parent)){
		flow += new_flow;
		int curr = t;
		while(curr != s){
			int prev = parent[curr];
			capacity[prev][curr] -= new_flow;
			capacity[curr][prev] += new_flow;
			curr = prev;
		}
	}

	return flow;
}

int main(){
	cin >> n >> m;

	capacity.resize(n, vector<long long> (n, 0));
	adj.resize(n);

	for(int i = 0; i < m; ++i){
		int src, dest;
	       	long long c; 
		cin >> src >> dest >> c;
		src--, dest--;
		
		adj[src].push_back(dest);
		adj[dest].push_back(src);
		capacity[src][dest] += c;		
	}

	long long ans =	maxFlow(0, n-1);	

	cout << ans << endl;	

	return 0;
}
