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

#define MOD (ll) (1e9 + 7)

int n;

signed main(){ _
    cin >> n; 

    vector<int> v(n);
    for(auto &x : v) cin >> x;

    sort(v.begin(), v.end());

    ll prev = 0, count_prev_distinct = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int x = v[i];

        if(x == prev){
            ans = (ans + count_prev_distinct + 1) % MOD;       
        } else {
            ans = (ans * 2 + 1) % MOD; 
        }

        if(i + 1 < n and v[i] != v[i + 1]){
            count_prev_distinct = ans;
        }

        prev = x;
    }
   
    cout << ans << endl;
	return 0;
}
