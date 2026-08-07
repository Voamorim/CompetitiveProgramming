#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){ _
	int n; cin >> n;
	
	int max = pow(2, n);
	bitset<18> b;
	bitset<18> g;

	for(int i = 0; i < max; i++){
		b = i;
		g[n-1] = b[n-1];
		for(int j = n-2; j >= 0; j--){
			g[j] = (b[j+1] + b[j])%2;
		}

		for(int j = 0; j < n; j++){
			cout << g[j];
		}
		cout << endl;
	}

	return 0;
}
