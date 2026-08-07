#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

#define MAX 1030

char mapa[MAX][MAX];
int n, m; 

bool valida(int i, int j){
    if(i >= n or i < 0 or j >= m or j < 0) return false;
    return mapa[i][j] == '.';
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int i, int j){
    stack<pair<int, int>> p;
    p.push({i, j});
    while(!p.empty()){
        pair<int, int> par = p.top();
        p.pop();
        mapa[par.first][par.second] = 'o';
        for(int i = 0; i < 4; i++){
            if(valida(par.first + dx[i], par.second + dy[i])){
                p.push({par.first + dx[i], par.second + dy[i]});
            }
        }
    }
}

int main(){ _
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mapa[i][j];
        }
    }
    int r = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mapa[i][j] == '.'){
                r++;    
                dfs(i, j);
            } 
        }
    }

    cout << r << endl;
    return 0;
}