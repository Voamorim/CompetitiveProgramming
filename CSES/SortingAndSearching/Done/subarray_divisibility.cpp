#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second

// Defines


// Variables


// Functions


int main(){ _
    int n; cin >> n;
    vector<ll> ps(n+1);
    for(int i = 1; i <= n; i++){
        cin >> ps[i];
        ps[i] %= n;
        ps[i] += n + ps[i-1];
        ps[i] %= n;
    }

    map<ll, int> mp;
    ll ans = 0;
    for(int i = 0; i <=n; i++){
        ll target = ps[i];
        ans += mp[target];
        mp[ps[i]]++;
    }

    cout << ans << endl;

    return 0;
}
