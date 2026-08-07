#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back
#define f first
#define s second

#define MAXN 200020

ll n, x;
vector<ll> p(MAXN);

int main(){ _
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		ll v; cin >> v;
		p[i+1] = p[i] + v;
	}

	ll ans = 0;

	map<ll, int> m;
	int i = 0;


	while(i <= n){
		ll  target = p[i]-x;
        ans += m[target];

		m[p[i]]++;
		i++;
	}
	cout << ans << endl;
	return 0;
}
