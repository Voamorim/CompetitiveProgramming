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

int n;

/*
* Ideia: a única coisa que importa é o menor valor que podemos colocar
*        em cada uma das posições do vetor para um vetor daquele tamanho
*           -> Mesmo que provoque que a subsequência resultante não seja a 
*              princípio válida, o tamanho da maior subsequência válida continua
*              preservado, ao mesmo tempo que se tenta minimizar os elementos 
*              para futuramente possivelmente construir uma subsequência maior
*/

signed main(){ _
    cin >> n;        

    vector<int> lis;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;

        // Calcula a posição do primeiro elemento maior ou igual ao valor
        // lido
        int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
       
        // Caso não tenha elemento maior que o novo valor, insere o valor no final,
        // o que faz com que a maior subsequência possível aumente de tamanho
        if(idx == lis.size()){
            lis.push_back(x);
        } else { 
            // Caso contrário, apenas minimiza o último valor da subsequência de
            // tamanho idx
            lis[idx] = x; 
        }
    }

    cout << lis.size() << endl;
	return 0;
}
