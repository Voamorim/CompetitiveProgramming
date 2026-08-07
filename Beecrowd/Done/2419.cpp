#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int valid(int i, int j){
    if(i >= n or j >= m or i < 0 or j < 0) return 0;

    return 1; 
}

int isCosta(char **matriz, int i, int j){
    for(int k = 0; k < 4; ++k){
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(not valid(ni, nj)) return 1;

        if(matriz[ni][nj] == '#'){
            continue; 
        }
        
        return 1;
    }
    return 0;
}

int main(){
    scanf("%d %d\n", &m, &n);

    char **matriz = (char**) malloc (sizeof(char*) * n);

    for(int i = 0; i < n; ++i){
        matriz[i] = (char*) malloc (sizeof(char) * m);
    }

    for(int i = 0; i < n; ++i){
        scanf("%s\n", matriz[i]);
    }

    long long ans = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(not valid(i, j)) continue; 
            if(matriz[i][j] == '.') continue;

            ans += isCosta(matriz, i, j);
        }
    }
    
    cout << ans << endl;

    return 0;
}
