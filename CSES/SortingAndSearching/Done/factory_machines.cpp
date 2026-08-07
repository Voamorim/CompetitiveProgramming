#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>

// Defines



// Variables
ll n, t;
vector<int> machines;
ll mmax = 0;

// Functions
bool check(ll t_available){
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll tmp = t_available / machines[i];
		ans = max(ans, ans + tmp);
	}

	return ans >= t;
}


int main(){ _    
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		machines.PB(x);
		mmax = max(mmax, x);		
	}
	mmax *= t;
	ll min = 1;

	while(mmax > min){
		ll mid = (mmax + min)/2;
		if(check(mid)){
			mmax = mid;
		} else {
			min = mid + 1;
		}
	}

	cout << min << endl;

	return 0;
}
