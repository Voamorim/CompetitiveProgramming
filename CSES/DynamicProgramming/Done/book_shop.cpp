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

// Defines



// Variables



// Functions



int main(){ _
    int n, max_price; cin >> n >> max_price;

    vector<int> prices(n); for(int i = 0; i < n; i++) cin >> prices[i];
    vector<int> pages(n); for(auto& p : pages) cin >> p;

    vector<vector<int>> dp(n + 1, vector<int> (max_price + 1, 0));

    // Itera sobre todos os livros
    for(int i = 0; i < n; i++){
        // Itera sobre todos os preços máximos
        for(int p = 0; p <= max_price; p++){
            // O máximo de páginas atual começa sendo o mesmo que antes de
            // poder utilizar o livro atual
            dp[i+1][p] = dp[i][p];

            // Caso o custo do livro atual seja menor que o dinheiro que
            // temos disponível...
            if(p >= prices[i]){
                dp[i+1][p] = max(dp[i+1][p], pages[i] + dp[i][p - prices[i]]);
            }
        }
    }


    cout << dp[n][max_price] << endl;

	return 0;
}
