#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define ii pair<int, int>

// Defines


// Variables


// Funcitions
void solve(int n){
	set<int> s;
	ll ans = 0;

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(s.count(x)){
			ans++;
			s.erase(x);	
		} else {
			s.insert(x);
		}
	}

	cout << ans << endl;
}



int main() { _
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		solve(n);
	}	


	return 0;
}
