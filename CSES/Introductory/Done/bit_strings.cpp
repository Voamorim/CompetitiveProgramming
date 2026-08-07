#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

#define MOD 1000000007

int main(){ _
	ll n; cin >> n;

	ll r = 2;
	for(int i = 1; i < n; i++){
		r = (r * 2) % MOD;
	}
	cout << r << endl;
	return 0;
}
