#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second
typedef long long ll;

//A prioridade deve ser em relação ao menor tempo já gasto possivel 

int main(){ _
    int N; cin >> N; //Num funcionários
    int M; cin >> M; //Num clientes

    //funcionario {tempo_gasto, {indice, tempo_necessario}}

    priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<>> fila;
    int funcionario;
    int tempo = 0; 

    for(int i = 0; i < N; i++){
        cin >> funcionario;
        fila.push({0, {i, funcionario}});
    }

    int cliente;
    for(int i = 0; i < M; i++){
        int t_necessario, t_gasto, indice;

        cin >> cliente;

        t_necessario = fila.top().s.s;
        indice = fila.top().s.f;
        t_gasto = fila.top().f;
        fila.pop();

        t_gasto += t_necessario *cliente;
        tempo = max(tempo, t_gasto);
        fila.push({t_gasto, {indice, t_necessario}});
    }
    cout << tempo << endl;
    return 0;
}