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
#define MAXN 101

// Variables
int n, m;
vector<vector<pair<int, ll>>> adj(MAXN);
vector<ll> dist(MAXN);
vector<bool> vis(MAXN);

// Functions
void dijkstra(int o){
	
}


int main(){ _
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].PB({b, c});
		adj[b].PB({a, c});
	}


	return 0;
}
