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

#define MOD (long long) (1e9 + 7)
#define MAXN 1000010

int n, t;
vector<vector<ll>> dp(2, vector<ll> (MAXN));
// dp[0]: quantas maneiras de preencher o retangulo com novos quadrados 
//        de lado 1.
//          - Expandindo: podemos adicionar quadrados de lado 1 expandindo os
//            dois lados, ou apenas um dos 2 lados (3 formas)
//          - Adicionando: podemos adicionar quadrados de lado 1 em cima do que
//            fizemos antes tanto para de lado 2 quanto para de lado 1 (2 formas)
// dp[1]: quantas maneiras de preencher o retangulo com um novo quadrado 
//        de lado 2
//          - Expandindo: podemos apenas expandir o que foi feito ate aqui 
//            contando com que o ultimo quadrado adicionado foi de lado 2 
//            (1 forma)
//          - Adicionando: podemos adicionar um novo retangulo de lado 2 por 
//            cima de um de lado dois ou de dois de lado 1 (2 formas)

signed main(){ _
    cin >> t;

    // Existe apenas uma forma de preencher um retangulo de n = 1 com 
    // quadradinhos
    dp[0][1] = 1; 

    // Existe apenas uma forma de preencher um retangulo de n = 1 com 
    // um retangulo de lado 2
    dp[1][1] = 1;

    for(int i = 2; i < MAXN; ++i){
        dp[0][i] = (dp[0][i-1] * 3) + (dp[1][i-1] + dp[0][i-1]);
        dp[1][i] = (dp[1][i-1]) + (dp[0][i-1] + dp[1][i-1]); 
        
        dp[0][i] %= MOD;
        dp[1][i] %= MOD; 
    }

    while(t--){
        cin >> n;

        cout << (dp[0][n] + dp[1][n]) % MOD << endl;
    }

	return 0;
}
