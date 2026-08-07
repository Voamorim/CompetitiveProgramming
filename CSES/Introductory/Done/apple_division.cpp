#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<int> v;

int getDiff(int g1, int g2){
	return abs(g1 - g2);
}

int solve(int g1, int g2, int i){
	if(i == n) return getDiff(g1, g2);

	return min(solve(g1 + v[i], g2, i+1), solve(g1, g2 + v[i], i+1));
}

signed main(){
	cin >> n;
	v.assign(n, 0);
	for(auto & x : v) cin >> x;

	cout << solve(0, 0, 0) << endl;
	

	return 0;
}
