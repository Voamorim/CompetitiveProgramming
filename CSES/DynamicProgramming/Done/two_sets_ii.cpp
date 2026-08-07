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

#define MOD 1000000007

int n;

int main(){ _
    cin >> n; 

    // Não é possível dividir todos os elementos para alcançar uma soma de 
    // n*(n+1)/4 se não é possível alcançar essa soma
    if(n * (n+1) % 4){
        cout << 0 << endl;
        return 0;
    }

    long long sum = n * (n+1) / 2; 

    long long dp[n+1][sum+1];
    memset(dp, 0, sizeof(long long) * (sum+1) * (n+1));

    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= sum; ++j){
            dp[i][j] = dp[i-1][j];
            if(j - i >= 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }

    cout << dp[n][sum/2] << endl;

	return 0;
}
