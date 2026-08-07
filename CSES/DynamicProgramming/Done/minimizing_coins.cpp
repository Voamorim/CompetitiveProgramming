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
vector<int> c(1000001);
vector<ll> min_coins;

// Functions
void solve(ll n, ll x){
    min_coins[0] = 0;
    for (int i = 1; i <= n; i++){
        for(int j = 0; j < x; j++){
            ll k = c[j];
            if(i - k >= 0)
                min_coins[i] = min(min_coins[i], min_coins[i-k]);
        }
        if(min_coins[i] != LLONG_MAX)
        min_coins[i]++;
    }
}


int main(){ _
    int n, x; cin >> x >> n;

    for(int i = 0; i < x; i++) cin >> c[i];

    min_coins.assign(n+1, LLONG_MAX);

    solve(n, x);

    if(min_coins[n] != LLONG_MAX)
    cout << min_coins[n] << endl;
    else cout << -1 << endl;
	return 0;
}
