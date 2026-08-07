#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char g[1010][1010];
int vis[1010][1010];

int n, m;
int r;

bool valid(int x, int y){
	if(x >= m or y >= n or x < 0 or y < 0 or g[y][x] == '#') return false;
	return true;
}

void dfs(int i, int j){
	vis[i][j] = true;
	for(int d = 0; d < 4; d++){
		int y = i + dy[d];
		int x = j + dx[d];
		if(valid(x, y)){
			if(!vis[y][x]) dfs(y, x);
		}
	}
}

int main(){ _
	cin >> n >> m;		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == '.' and vis[i][j] == false){
				dfs(i, j);
				r++;
			}
		}
	}

	cout << r << endl;
	return 0;
}
