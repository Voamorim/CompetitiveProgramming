#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back
#define f first
#define s second

// Defines
#define MAXN 500
#define MAXC 1e18

// Variables
int n, m, q;
vector<vector<ll>> cost(MAXN, vector<ll> (MAXN, MAXC));

// Functions

void floyd(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				cost[i][j] = cost[j][i] = min(cost[i][j], cost[i][k] + cost[k][j]);				
			}
		}
	}
}


int main(){ _
	cin >> n >> m >> q;
	
	ll a, b, c;

	for(int i = 0; i < m; i++){
		cin >> a >> b >> c; a--, b--;
		cost[a][b] = cost[b][a] =  min(cost[a][b], c);	
	}

	floyd();

	for(int i = 0; i < q; i++){
		cin >> a >> b; a--, b--;
		c = a == b ? 0 : cost[a][b] == MAXC ? -1 : cost[a][b];

		cout << c << endl;
	}

	return 0;
}
