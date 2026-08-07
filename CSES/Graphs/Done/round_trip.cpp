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
vector<vector<int>> adj(MAXN);
vector<int> level(MAXN);
vector<int> par(MAXN);

bool possible = false;

int main(){ _
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int o, d; cin >> o >> d;
		adj[o].pb(d);
		adj[d].pb(o);
	}

	for(int i = 0; i < n; i++){
		if(
	}
	return 0;
}
