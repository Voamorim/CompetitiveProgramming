#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back
#define f first
#define s second

typedef long long ll;

// Defines
#define MAXN 50010

// Variables
int n;
ll sum;
map<ll, int> m;

// Functions
ll complement(ll num){
	ll lower = num / 7;
	return num - lower*7;
}


int main(){ _

	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	
	cin >> n;	
	ll ans = 0;
	
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		sum += x;
		ll comp = complement(sum);
		auto c = m.find(comp);
		if(c != m.end()){	
			ll aux = i - m[comp];
			ans = aux > ans ? aux : ans;			
		}

		c = m.find(sum%7);
		if(c == m.end()) m[sum%7] = i;
	}	
	cout << ans << endl;
	return 0;
}
