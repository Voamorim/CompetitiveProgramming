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
#define MAXN 5001

// Variables
vector<vector<int>> dp(MAXN, vector<int> (MAXN));

// Functions

int main(){ _
    string a, b; cin >> a >> b;

    for(int i = 0; i < MAXN; i++) {
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;

	return 0;
}
