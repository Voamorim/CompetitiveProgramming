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

#define MAXN 1010

int n, q;
vector<vector<int>> prefix_sum(MAXN, vector<int> (MAXN));


int main(){ _
    cin >> n >> q;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char c; cin >> c;
            prefix_sum[i][j] = prefix_sum[i-1][j] +
                               prefix_sum[i][j-1] -
                               prefix_sum[i-1][j-1] +
                               (c == '*' ? 1 : 0);
        }
    }

    while(q--){
        int j1, i1, j2, i2; 
        cin >> i1 >> j1 >> i2 >> j2;
        
        int ans = prefix_sum[i2][j2];
        ans -= prefix_sum[i2][j1 - 1];
        ans -= prefix_sum[i1 - 1][j2];
        ans += prefix_sum[i1 - 1][j1 - 1];
        
        cout << ans << endl;
    }

	return 0;
}
