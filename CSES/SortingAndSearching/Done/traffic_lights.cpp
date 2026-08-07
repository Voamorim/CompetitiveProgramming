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
int x, n;
set<pair<int, int>> s;
multiset<int> d;
bool nfirst;

// Functions
void print(int g){
	if(nfirst)
		cout << ' ' << g;
	else{
		cout << g;
		nfirst = true;
	}
}


int main(){ _
	cin >> x >> n;
	s.insert(MP(0, -x));
	d.insert(x);

	while(n--){
		int t; cin >> t; t = -t;
		
		auto p = s.lower_bound(MP(t, t));

		int l = (*p).F;
		int r = (*p).S;
		
		int dif = fabs(l - r);
		
		auto e = d.find(dif);
		d.erase(e);

		s.erase(p);
		

		s.insert(MP(l, t));
		s.insert(MP(t, r));
		d.insert(fabs(l - t));
		d.insert(fabs(t - r));

		print(*d.rbegin());
	}	
	cout << endl;
	return 0;
}
