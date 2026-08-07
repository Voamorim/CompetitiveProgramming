#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

int main(){
    long long q, k;
    scanf("%lld %lld\n", &q, &k);

    vector<long long> dp(k + 1, 0);
    dp[0] = 1;

    for(int t = 0; t < q; ++t){
        char c; long long x;
        scanf("%c %lld\n", &c, &x);

        if(c == '+'){
            for(int i = k; i >= x; --i){
                dp[i] = (dp[i] + dp[i - x]) % MOD;
            }
        } else {
            for(int i = x; i <= k; ++i){
                dp[i] = (dp[i] - dp[i - x] + MOD) % MOD;
            }
        }
        
        printf("%lld\n", dp[k]);
    }
    return 0;
}
