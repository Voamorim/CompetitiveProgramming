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
ii solve(int k){
	set<int> s;
	int total = k-2;
	ii ans = {0, 0};
	bool ok = false;

	for(int i = 0; i < k; i++){
		int x; cin >> x;
		if(ok) continue;
		if(x and total % x == 0){
			int target = total / x;
			
			auto p = s.find(target);
			if(p != s.end()){
				ans = {x, *p};
				ok = true;
			} 
		}
		s.insert(x);
	}
	return ans;
}

int main() { _
	int t; cin >> t;
	while(t--){
		int k; cin >> k;
		ii ans = solve(k);
		cout << ans.F << " " << ans.S << endl;
	}	
	return 0;
}
