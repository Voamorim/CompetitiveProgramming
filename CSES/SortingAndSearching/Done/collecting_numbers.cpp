#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto & x : v) cin >> x;

	long long ans = 0;
	set<int> s;
	for(int i = 0; i < n; ++i){
		auto it = s.find(v[i] - 1);

		ans += (it == s.end());
		s.insert(v[i]);
	}
	cout << ans << endl;	

	return 0;
}
