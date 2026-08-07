#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

#define MAXN 100010

int n, m;
vector<vector<int>> adj (MAXN);
vector<bool> vis(MAXN);

void bfs(int o){
	queue<int> q;
	vis[o] = true;
	q.push(o);

	while(!q.empty()){
		int w = q.front();
		q.pop();

		for(int x : adj[w]){
			if(!vis[x]){
				vis[x] = true;
				q.push(x);
			}
		}
	}
}

int main(){ _
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int o, d; cin >> o >> d;
		o--, d--;
		
		adj[o].push_back(d);
		adj[d].push_back(o);
	}
	
	int qnt = 0;
	vector<int> v;

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			bfs(i);
			qnt++;
			v.push_back(i+1);
		}
	}	
	qnt--;
	cout << qnt << endl;

	for(int i = 1; i < v.size(); i++){
		cout << v[i-1] << ' '  << v[i] << endl;
	}

	return 0;
}
