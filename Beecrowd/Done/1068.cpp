#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

//Aqui é definida a macro "-", que será colocado mais na frente no código
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second

//Função útil de debugging, basta escrever "dbg(a)" que printará "a = val a":
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

//0 para abre, 1 para fecha

int main(){ _
    queue<int> fila;
    string expressao;
    while(cin >> expressao){
        int qnt_abre = 0, qnt_fecha = 0;
        bool resultado = true;
        for(int c = 0; c < size(expressao); c++){
            if(expressao[c] == '(') fila.push(0);
            if(expressao[c] == ')') fila.push(1);
        }
        int tam_fila = fila.size();
        int atual;
        for(int i = 0; i < tam_fila; i++){
            atual = fila.front(); fila.pop();
            if(not atual) qnt_abre++;
            else qnt_fecha++;

            if(qnt_abre < qnt_fecha) resultado = false;
        }
        if(qnt_abre != qnt_fecha) resultado = false;
        
        if(resultado) cout << "correct" << endl;
        else cout << "incorrect" << endl;
    }
    return 0;
}