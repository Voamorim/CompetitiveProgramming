#include <bits/stdc++.h>

using namespace std;

#define MOD (long long) (1e9 + 7)
	
long long fastPow(long long a, long long b){
	long long ans = 1;
	while(b > 0){
		if(b % 2 == 1)
			ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}

	return ans;
}

int main(){
	int n; cin >> n;

	while(n--){
		long long a, b; cin >> a >> b;

		cout << fastPow(a, b) << endl;
	}	

	return 0;
}
