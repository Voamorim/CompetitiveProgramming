#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl

typedef long long ll;

int n, c; 
string s;

void iguala1(vector<vector<int>> &adj){
	for(int i = 0, j = n - 1; i <= j; i++, j--){
		if(isalpha((unsigned char) s[i]) and !isalpha((unsigned char) s[j])){
			s[j] = s[i];
		}	

		if(!isalpha((unsigned char) s[i]) and isalpha((unsigned char) s[j])){
			s[i] = s[j];
		}

		adj[i].push_back(j);
		adj[j].push_back(i);
	}	
}

void criaAdj(vector<vector<int>> &adj){
	int x, y;
	for(int i = 0; i < c; i++){
		cin >> x >> y; x--, y--;

		if(isalpha((unsigned char) s[x]) and !isalpha((unsigned char) s[y])){
			s[y] = s[x];
		}	

		if(!isalpha((unsigned char) s[x]) and isalpha((unsigned char) s[y])){
			s[x] = s[y];
		}

		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void iguala2(int i, int j){
	if(isalpha((unsigned char) s[i]) and !isalpha((unsigned char) s[j])){
		s[j] = s[i];
	}	

	if(!isalpha((unsigned char) s[i]) and isalpha((unsigned char) s[j])){
		s[i] = s[j];
	}
}

void bfs(vector<vector<int>> &adj, vector<bool> &vis){
	queue<int> q;
	vis[0] = true;
	q.push(0);

	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : adj[u]){
			iguala2(v, u);
			
			if(!vis[v]){
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

int main(){
	cin >> n >> c;	
	cin >> s;
	vector<vector<int>> adj(n);
	vector<bool> vis(n);

	iguala1(adj);
	criaAdj(adj);

	ll r = 1;
	for(int i = 0, j = n - 1; i <= j; i++, j--){
		if(s[i] == s[j] and s[i] == '*'){
			r *= 26;
			s[i] = 'a', s[j] = 'a';

			for(int k = 0; k < adj[i].size(); k++){
				int d = adj[i][k];
				s[d] = 'a';
			}
			for(int k = 0; k < adj[j].size(); k++){
				int d = adj[j][k];
				s[d] = 'a';
			}
		}
	}

	cout << r % (1000000000 + 7) << endl;

	return 0;
}
