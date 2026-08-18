#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define MOD ((long long) 1e9 + 7)

int n, m;

int main(){ _
    cin >> n >> m;
    vector<vector<int>> graph (n, vector<int> (m, 0));

    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        x--, y--;

        graph[x][y] += 1;
    }

    // dp[mask][end_node]
    vector<vector<long long>> dp (1 << n, vector<long long> (n, 0));

    dp[1][0] = 1;

    for(int mask = 1; mask < (1 << n); ++mask){
        for(int v = 0; v < n; ++v){
            if((mask & (1 << v)) == 0) continue;
            if(dp[mask][v] == 0) continue;

            for(int u = 0; u < n; ++u){
                if((mask & (1 << u)) or (not graph[v][u])) continue;

                dp[mask | 1 << u][u] = (dp[mask | 1 << u][u] + (dp[mask][v] * graph[v][u] % MOD)) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n-1] << endl;
    return 0;
}
