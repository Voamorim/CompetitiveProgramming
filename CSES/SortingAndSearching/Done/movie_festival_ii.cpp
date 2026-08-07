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

// Defines



// Variables



// Functions



int main(){ _
	int n, m; cin >> n >> m;
	multiset<int> s;
	for(int i = 0; i < m; i++) s.insert(0);


	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		
		v.PB({b, a});
	}
	sort(v.begin(), v.end());
		
	ll ans = 0;

	for(int i = 0; i < n; i++){
		auto p = s.lower_bound(-v[i].S);
		if(p != s.end()){
			ans++;		
			s.erase(p);
			s.insert(-v[i].F);
		}
	}

	cout << ans << endl;

	return 0;
}
