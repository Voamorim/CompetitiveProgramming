#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){ _
	int n; cin >> n;
	
	ll qnt = 0;
	for(int i = 5; i <= n; i*=5){
		qnt += n / i;
	}
	cout << qnt << endl;

	return 0;
}
