#include <bits/stdc++.h>

using namespace std;

#define MOD (long long) (1e9 + 7)
#define ll long long

// estrategia: calcular o fastpow de d = b^c mod (1e9+7 - 1), ja que os expoentestrabalham em mod - 1 quando a base trabalha em mod
//
// depois basta calcular o fastpow de a^d

ll fastPow(ll a, ll b, ll mod){
	ll ans = 1;
	while(b > 0){
		if(b % 2 == 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}

int main(){
	int n; cin >> n;

	while(n--){
		ll a, b, c; cin >> a >> b >> c;

		ll d = fastPow(b, c, MOD - 1);

		cout << fastPow(a, d, MOD) << endl;
	}

	return 0;
}
