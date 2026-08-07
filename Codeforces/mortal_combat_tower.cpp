#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n;

vector<int> bosses (MAXN);

void solve(){
    int INF = 1e9;

    vector<vector<vector<int>>> dp(n, 
                                   vector<vector<int>> (3, 
                                   vector<int> (2, INF)));
    // [idx, rounds, [0 == eu, 1 == amigo]];

    dp[0][1][1] = bosses[0] == 1;

    for(int i = 1; i < n; ++i){
        // Deixo o amigo continuar jogando
        dp[i][2][1] = min(dp[i][2][1], dp[i-1][1][1] + (bosses[i] == 1));

        // Continuo jogando 
        if(i > 1){
            dp[i][2][0] = min(dp[i][2][0], dp[i-1][1][0]); 
        }

        // Amigo eh obrigado a passar para minha vez
        if(i > 1){
            dp[i][1][0] = min(dp[i][1][0], dp[i-1][2][1]);
        }

        // Eu sou obrigado a passar para o amigo
        if(i > 1){
            dp[i][1][1] = min(dp[i][1][1], dp[i-1][2][0] + (bosses[i] == 1));
        }

        // Passo opcionalmente para o amigo
        dp[i][1][1] = min(dp[i][1][1], dp[i-1][1][0] + (bosses[i] == 1));

        // Amigo passa opcionalmente para mim
        dp[i][1][0] = min(dp[i][1][0], dp[i-1][1][1]);
    }

    /*
    for(auto &e : dp){
        for(auto &r : e){
            for(auto &a : r) cout << a << ' ';
            cout << endl; 
        }
        cout << endl;
    }
    */

    int ans = INF;

    ans = min(min(min(dp[n-1][1][0], dp[n-1][2][0]), dp[n-1][1][1]), dp[n-1][2][1]);

    cout << ans << endl;
}

int main(){
    int t; cin >> t; 
   
    while(t--){
        cin >> n;

        for(int i = 0; i < n; ++i) cin >> bosses[i];

        solve();
    }

    return 0;
}
