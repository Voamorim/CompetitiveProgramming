#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

/* 2*10⁵ elementos 
 * e números de 1 - 1000
 *
 * Sempre terão números repetidos se n > 1000
 * */


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(1001, 0);
		for(int i = 1; i <= n; i++){
			int x; cin >> x;
			a[x] = !a[x] ? i : max(i, a[x]);
		}
		
		int r = -1;

		for(int i = 1; i < 1001; i++ ){
			for(int j = 1; j < 1001; j++){
				if(a[i] and a[j])
				if(__gcd(i, j) == 1){
					r = max(r, a[i] + a[j]);
				}
			}
		}

		cout << r << endl;
	}
	return 0;
}
