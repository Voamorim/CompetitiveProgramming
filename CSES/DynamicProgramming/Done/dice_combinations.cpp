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
#define mod 1000000007


// Variables
vector<ll> v(1000010);


// Functions
void solve(ll n){
    // Existe apenas uma maneira de construir a soma 0
    v[0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                v[i] = (v[i] + v[i-j]) % mod;
            }
        }
    }
}


int main(){ _

    ll n; cin >> n;
    solve(n);
    cout << v[n] << endl;

	return 0;
}
