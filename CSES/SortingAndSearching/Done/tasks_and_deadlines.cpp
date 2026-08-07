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

// Defines



// Variables



// Functions



int main(){ _
	int n; cin >> n;
	vector<ii> v;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		v.PB({a, b});
	}	
	sort(v.begin(), v.end());
	
	ll ans = 0, time = 0;
	for(int i = 0; i < n; i++){
		time += v[i].F;
		ans += v[i].S - time;
	}
	cout << ans << endl;
	return 0;
}
