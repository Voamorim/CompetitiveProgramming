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



// Functions



int main(){ _
    int n; cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    ll larger = -LONG_MAX;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
        larger = max(larger, v[i]);
    }
    ll ans = 0;
    if(sum-larger < larger){
        ans = sum + (larger - (sum - larger));
    } else {
        ans = sum;
    }
    cout << ans << endl;

	return 0;
}
