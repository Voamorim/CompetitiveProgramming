#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define s second
#define f first

typedef long long ll;

char g[1010][1010];
int dist[1010][1010];
pair<int, int> par[1010][1010];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

bool valid(int i, int j){
	if(i >= n or j >= m or i < 0 or j < 0 or g[i][j] == '#') return false;
	return true;
}

void bfs(int i, int j){
	queue<pair<int, int>> q;

	dist[i][j] = 0;
	q.push({i, j});

	while(!q.empty()){
		pair<int, int> w = q.front();
		q.pop();

		for(int d = 0; d < 4; d++){
			int y = dy[d] + w.f;
			int x = dx[d] + w.s;
		
			if(valid(y, x) and dist[y][x] == -1){
				dist[y][x] = dist[w.f][w.s] + 1;
				q.push({y, x});
				par[y][x] = {w.f, w.s};
			}
		}
	}
}

int main(){ _
	cin >> n >> m;
	
	memset(dist, -1, sizeof dist);
	
	pair<int, int> src;
	pair<int, int> dest;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
			if(g[i][j] == 'A'){
				src = {i, j};
			}
			if(g[i][j] == 'B'){
				dest = {i, j};
			}
		}
			
	bfs(src.f, src.s);

	string s;

	if(dist[dest.f][dest.s] != -1){
		cout << "YES" << endl;
		cout << dist[dest.f][dest.s] << endl;
		
		int i = dest.f, j = dest.s;
		
		while(i != src.f or j != src.s){
			if(par[i][j].f - i == 0 and par[i][j].s - j == 1){
				s.push_back('L');
			}
			if(par[i][j].f - i == 0 and par[i][j].s - j == -1){
				s.push_back('R');
			}
			if(par[i][j].f - i == 1 and par[i][j].s -j == 0){
				s.push_back('U');
			}
			if(par[i][j].f - i == -1 and par[i][j].s - j == 0){
				s.push_back('D');
				
			}
			int tmp = i;
			i = par[i][j].f;
			j = par[tmp][j].s;
		}	
		for(int k = s.size() - 1; k >= 0; k--){
			cout << s[k];
		} 
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
