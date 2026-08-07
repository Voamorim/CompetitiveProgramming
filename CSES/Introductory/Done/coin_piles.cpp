#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){ _
	int t; cin >> t;
	while(t--){
		ll a, b; cin >> a >> b;
		bool r = true;	

		if(a < b) swap(a, b);	
		
		if(a > 2*b) r = false;
		if(!(2*(a+b) % 3 == 0)) r = false;

		if(r) cout << "YES\n";
	       	else cout << "NO" << endl;	
	}

	return 0;
}
