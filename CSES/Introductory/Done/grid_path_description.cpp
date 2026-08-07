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

int n = 7;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

vector<vector<bool>> vis(8, vector<bool> (8));

string moves;

bool isValid(int i, int j){
    if(i < 0 or j < 0 or i >= n or j >= n) return false;
    return true;
}

int solve(int i, int j, int idx){
    if(vis[i][j]) return 0;

    // Caso tenha chegado ao final da string, basta verificar se estamos na
    // posição final correta
    if(idx == moves.size()){
        return (i == 6 and j == 0);
    }

    // Caso o destino seja visitado antes da hora, o caminho não é válido
    if(i == 6 and j == 0) return 0;

    bool sides_unvisited = false;
    if(isValid(i, j-1) and isValid(i, j+1)) 
        sides_unvisited = not vis[i][j-1] and not vis[i][j+1];

    // Verifica se a matriz foi dividida em duas a partir do quadrado superior

    bool hit_border = not isValid(i - 1, j);
    bool hit_visited = isValid(i-1, j) ? vis[i-1][j] : false;  
    bool is_prev_visited = isValid(i+1, j) ? vis[i+1][j] : false;

    if((hit_border or hit_visited) and is_prev_visited and sides_unvisited)
        return 0;

    // Pelo quadrado inferior

    hit_border = not isValid(i+1, j);
    hit_visited = isValid(i+1, j) ? vis[i+1][j] : false;
    is_prev_visited = isValid(i-1, j) ? vis[i-1][j] : false;

    if((hit_border or hit_visited) and is_prev_visited and sides_unvisited)
        return 0;

    // Pelo quadrado da esquerda

    sides_unvisited = false;
    if(isValid(i - 1, j) and isValid(i + 1, j))
        sides_unvisited = not vis[i-1][j] and not vis[i+1][j];

    hit_border = not isValid(i, j - 1);
    hit_visited = isValid(i, j - 1) ? vis[i][j-1] : false;
    is_prev_visited = isValid(i, j + 1) ? vis[i][j + 1] : false;

    if((hit_border or hit_visited) and is_prev_visited and sides_unvisited)
        return 0;

    // Pelo quadrado da direita

    hit_border = not isValid(i, j + 1);
    hit_visited = isValid(i, j + 1) ? vis[i][j+1] : false;
    is_prev_visited = isValid(i, j - 1) ? vis[i][j-1] : false;

    if((hit_border or hit_visited) and is_prev_visited and sides_unvisited)
        return 0;

    // Verifica se a diagonal foi visitada mas os quadrados que levam até a
    // essa diagonal ambos não foram
    
    // Para a diagonal direita superior
    bool diagonal_visited = false;
    if(isValid(i - 1, j + 1))diagonal_visited = vis[i-1][j+1]; 
    if(diagonal_visited and not vis[i-1][j] and not vis[i][j+1]) return 0;

    // Para a digoanal direita inferior
    diagonal_visited = isValid(i+1, j+1) ? vis[i+1][j+1] : false;
    if(diagonal_visited and not vis[i+1][j] and not vis[i][j+1]) return 0;

    // Para a diagonal superior esquerda
    diagonal_visited = isValid(i-1, j-1) ? vis[i-1][j-1] : false;
    if(diagonal_visited and not vis[i-1][j] and not vis[i][j-1]) return 0;

    // Para a diagonal inferior esquerda
    diagonal_visited = isValid(i+1, j -1) ? vis[i+1][j-1] : false;
    if(diagonal_visited and not vis[i+1][j] and not vis[i][j-1]) return 0;

    // Marca a posição como visitada
    vis[i][j] = true;

    // Conta a quantidade de caminhos a partir dos movimentos permitidos pela
    // string de entrada
    int count_paths = 0;
    if(moves[idx] == '?'){
        for(int k = 0; k < 4; ++k){
            if(isValid(i + dx[k], j + dy[k]))
                count_paths += solve(i + dx[k], j + dy[k], idx + 1);
        }
    } else if(moves[idx] == 'U'){
        if(isValid(i - 1, j)) count_paths += solve(i - 1, j, idx + 1);
    } else if(moves[idx] == 'D'){
        if(isValid(i + 1, j)) count_paths += solve(i + 1, j, idx + 1);
    } else if(moves[idx] == 'L'){
        if(isValid(i, j - 1)) count_paths += solve(i, j - 1, idx + 1);
    } else {
        if(isValid(i, j + 1)) count_paths += solve(i, j + 1, idx + 1);
    }
   
    // Realiza o backtracking
    vis[i][j] = false;

    // Retorna a quantidade de caminhos válidos encontrados
    return count_paths;
}

signed main(){ _
    cin >> moves;

    cout << solve(0, 0, 0) << endl;

	return 0;
}
