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

#define MAXN 21

int n, x;
vector<pii> dp(1 << MAXN, {INT_MAX, INT_MAX});
vector<int> people(MAXN);

signed main(){ _
    cin >> n >> x; 

    for(int i = 0; i < n; ++i)
        cin >> people[i];

    // Caso base: com 0 pessoas é necessário dar uma volta com 0 peso ocupado
    dp[0] = make_pair(1, 0);

    // Itera por cada uma das possibilidades de levar ou não uma pessoa
    for(int mask = 1; mask < (1 << n); ++mask){

        // Itera por cada uma das pessoas
        for(int i = 0; i < n; ++i){

            // Caso o bit esteja setado na máscara 
            if((1 << i) & mask){
                auto [rides, space_without] = dp[mask ^ (1 << i)];

                // Caso a pessoa couber no elevador 
                if(space_without + people[i] <= x){ 
                    dp[mask] = min(dp[mask], 
                                   {rides, space_without + people[i]});
                } else {
                // Caso a pessoa seja pesada demais
                    dp[mask] = min(dp[mask],
                                   {rides + 1, people[i]});
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1].F << endl;

	return 0;
}
