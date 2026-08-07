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

const ll mod = 1000000000 + 7;

// Variables



// Functions



int main(){ _
    int n; cin >> n;

    vector<vector<ll>> r(n, vector<ll> (n, 0));

    vector<vector<char>> m(n, vector<char> (n));
    for(auto& i : m){
        for(auto& j: i){
            cin >> j;
        }
    }

    if(m[0][0] != '*')
    r[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == '*') continue;
            if(i - 1 >= 0){
                r[i][j] = (r[i][j] + r[i-1][j]) % mod;
            }
            if(j - 1 >= 0){
                r[i][j] = (r[i][j] + r[i][j-1]) % mod;
            }
        }
    }

    cout << r[n-1][n-1] << endl;

	return 0;
}
