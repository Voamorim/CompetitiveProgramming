#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

#define MAXN 1001

int n;
int matrix[MAXN][MAXN]; 

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, -2, 2, 1, -1};

bool check(int i, int j){
    if(i < 0 or j < 0 or i >= n or j >= n) return false;
    if(i == 0 and j == 0) return false;
    return true;
}

void solve(){
    queue<pii> q;
    q.push({0, 0});

    while(not q.empty()){
        pii curr = q.front(); q.pop();

        for(int i = 0; i < 8; ++i){
            int x = curr.F + dx[i];
            int y = curr.S + dy[i];

            if(not check(x, y)) continue;
           
            int new_cost = matrix[curr.F][curr.S] + 1;

            if(matrix[x][y] > new_cost or matrix[x][y] == 0){
                matrix[x][y] = new_cost;
                q.push({x, y});
            }
        }
    }    

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << matrix[i][j] << (j == n-1 ? endl : ' ');
        }
    }
}

signed main(){ _
    cin >> n;  
    solve();
	return 0;
}
