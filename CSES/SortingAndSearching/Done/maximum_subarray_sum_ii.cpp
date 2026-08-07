#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<ll, ll>
#define piii pair<int, pair<int, int>>

// Defines



// Variables



// Functions



int main(){ _
    int n, a, b; cin >> n >> a >> b;
    vector<ll> ps(n + 1);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        ps[i] = ps[i-1] + x;
    }
    int i = 0, j = b;
    set<pii> s;
    for(int k = a; k <= j; k++)
        s.insert({-ps[k], k});
    ll ans = -LONG_MAX;
    while(i <= n - a){
        auto m = s.lower_bound({-LONG_MAX, 0});
        ans = max(ans, -(*m).F - ps[i]);
        //dbg(-(*m).F - ps[i]);
        //dbg(i);
        s.erase({-ps[j-(b-a)], j-(b-a)});
        i++;
        j++;
        if(j <= n) s.insert({-ps[j], j});
    }
    cout << ans << endl;
	return 0;
}
