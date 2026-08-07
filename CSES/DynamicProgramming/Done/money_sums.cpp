#include <bits/stdc++.h>

typedef long long ll;

#define MAX_SUM 100000

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<vector<bool>> dp(n+1, vector<bool> (MAX_SUM+1));

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= MAX_SUM; j++){
            dp[i][j] = dp[i-1][j]; // Mantém as somas formadas com moedas anteriores
            int prev_sum = j - c[i-1];
            if(prev_sum >= 0 and dp[i-1][prev_sum]){
                dp[i][j] = dp[i-1][prev_sum];
            }
        }
    }
    vector<int> r;

    for(int j = 1; j <= MAX_SUM; j++){
        if(dp[n][j]) r.push_back(j);
    }

    cout << r.size() << endl;
    for(auto x : r) cout << x << ' ';
    cout << endl;

    return 0;
}
