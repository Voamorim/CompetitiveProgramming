#include <bits/stdc++.h>

using namespace std;

#define dgb(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define s second
#define f first

typedef long long ll;

#define MAX 1010

bool possible = false;

int n, m;
vector<pair<int, int>> d = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

vector<vector<int>> g(MAX, vector<int> (MAX));
queue<pair<int, int>> monsters;

map<pair<int, int>, pair<int, int>> par_map;
pair<int, int> player, saida;

// Verifica se a posição é 
bool isValid(int i, int j, int t){
	if(i < 0 or j < 0 or i >= n or j >= m) 
		return false;
	
	// Caso o novo valor para a posição seja maior ou igual a aquela que já está
	if(g[i][j] <= t)
		return false;

	return true;
}

// Verifica se a posição é uma das saídas do labirinto
bool isExit(int i, int j, int t){
	if(!isValid(i, j, t)) return false;

	if(i == 0 or j == 0 or i == n-1 or j == m-1) return true;

	return false;
}

// BFS apenas do player
void playerBfs(){
	queue<pair<ll, pair<int, int>>> q;
	q.push({0, player});

	// Posição inicial do player não possui nó antecessor
	par_map[player] = {-1, -1};

	while(!q.empty()){
		int i = q.front().s.f;
		int j = q.front().s.s;
		int dist = q.front().f;
		
		q.pop();
		dist++;

		for(int k = 0; k < 4; k++){
			// Novas coordenadas
			pair<int, int> n = {i + d[k].f, j + d[k].s};

			// Verifica se o novo nó a ser acessado é uma saída
			if(isExit(n.f, n.s, dist)){
				par_map[n] = {i, j}; 
				possible = true;
				saida = n;
				g[n.f][n.s] = dist;
				return;
			}

			// Verifica se é possível chegar na nova coordenada
			if(isValid(n.f, n.s, dist)){
				par_map[n] = {i, j};
				g[n.f][n.s] = dist;
				q.push({dist, n});
			}
		}	
	}
}

// BFS de todos os monstros ao mesmo tempo
void monstersBfs(){
	queue<pair<ll, pair<int, int>>> q;
	
	while(!monsters.empty()){
		pair<int, int>  m = monsters.front(); 
		monsters.pop();
		q.push({0, m});
	}

	while(!q.empty()){
		int i = q.front().s.f;
		int j = q.front().s.s;
		int dist = q.front().f;

		dist++; 
		q.pop();

		for(int k = 0; k < 4; k++){
			pair<int, int> n = {i + d[k].f, j + d[k].s};
			if(isValid(n.f, n.s, dist)){
				g[n.f][n.s] = dist;
				q.push({dist, n});
			}
		}
	}
}

int main(){ _
	cin >> n >> m;

	// Leitura e marcação do grafo
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c == 'A') player = {i, j};
			if(c == 'M') monsters.push({i, j});
			if(c == '#') g[i][j] = 0;
			if(c == '.') g[i][j] = INT_MAX;
		}
	}

	// Verifica se o player nasceu em alguma saída
	if(player.f == 0 or player.s == 0 or player.f == n-1 or player.s == m-1){
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	
	monstersBfs();
	playerBfs();

	// Verifica se não foi possivel encontrar uma saída
	if(!possible){
		cout << "NO" << endl;
		return 0;
	}
	
	// Imprime que foi possível, a distância e o caminho para a saída
	cout << "YES" << endl;
	cout << g[saida.f][saida.s] << endl;

	stack<char> p;
	pair<int, int> atual = saida;
	pair<int, int> ant = par_map[atual];

	while(ant.f != -1 and ant.s != -1){
		if(atual.s - ant.s == 1) p.push('R');
	       	if(atual.s - ant.s == -1) p.push('L');
		if(atual.f - ant.f == 1) p.push('D');
		if(atual.f - ant.f == -1) p.push('U');
	
		atual = ant;
		ant = par_map[ant];
	}

	while(!p.empty()){
		auto c = p.top();
		p.pop();
		cout << c;
	}
	cout << endl;

	return 0;
}
