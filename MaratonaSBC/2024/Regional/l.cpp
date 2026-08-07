#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl

typedef long long ll;

ll l[65];

int main(){ _
	int n; cin >> n; 
	for(int i = 0; i < n; i++){
		int num; cin >> num;
		bitset<64> b(num);
	    for(int j = 63; j >= 0; j--){
	    	l[j] += b[j];
	    }
	}
	for(int i = 0; i < n; i++){
		ll r = 0;
		for(int j = 63; j >= 0 ; j--){
			if(l[j]){
				r += pow(2, j);
				l[j]--;
			}
		}
		if(i == n -1) cout << r << endl;
		else cout << r << " ";
	}
	return 0;
}
