#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 100010

ll n, g;
vector<ll> capivaras(MAXN);

bool possible(ll t){
    __int128_t ans = 0;

    for(ll i = 0; i < n; ++i){
        ans += t/capivaras[i];
    }

    return ans >= (__int128_t) g;
}

int main(){
    cin >> n >> g; 

    for(ll i = 0; i < n; ++i){
        ll c; cin >> c;
        capivaras[i] = c;
    }

    ll l = 1, h = 1000000000000000010LL;

    while(l < h){
        ll mid = (l + h) / 2;
    
        if(possible(mid)){
            h = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}
