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
vector<ll> combinations(1000010);
vector<int> coins;

// Functions
void solve(ll x){

    // Existe apenas uma maneira de construir a soma 0
    combinations[0] = 1;

    for(int k = 1; k <= x; k++){
        for(auto c : coins){
            if(k - c >= 0){
                combinations[k] = (combinations[k] + combinations[k-c]) % mod;
            }
        }
    }
}


int main(){ _
    ll n, x; cin >> n >> x;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        coins.PB(k);
    }


    solve(x);

    cout << combinations[x] << endl;

	return 0;
}
