#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second

// Defines

// Variables
int n, m;
multiset<int> s;
vector<int> t, ans;

// Functions



int main(){ _
	cin >> n >> m;
	ans.resize(m);
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		s.insert(-a);
	}	

	for(int i = 0; i < m; i++){
		int a; cin >> a;
		a = -a;

		
		auto p = s.lower_bound(a);
		if(p == s.end()) ans[i] = -1;
		else{
			int x = *p;
		       	ans[i] = -x;

			s.erase(p);
		}
	}

	for(int i = 0; i < m; i++) cout << ans[i] << endl;

	
	return 0;
}
