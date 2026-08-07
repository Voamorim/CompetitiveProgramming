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

int a, b;

int main(){ _
    cin >> a >> b; 

    vector<vector<int>> dp(a + 1, vector<int> (b+1, 0)); 

    for(int i = 1; i <= a; ++i){
        for(int j = 1; j <= b; ++j){
            // Caso base: retângulo de lados iguais já é um quadrado
            if(i == j){ 
                dp[i][j] = 0;
                continue; 
            }

            int minimum = INT_MAX;
            for(int k = 1; k < i; ++k){
                minimum = min(minimum, dp[i-k][j] + dp[k][j]);
            }
            for(int l = 1; l < j; ++l){
                minimum = min(minimum, dp[i][j-l] + dp[i][l]);
            }
            dp[i][j] = 1 + minimum;
        }
    }

    cout << dp[a][b] << endl;

	return 0;
}
