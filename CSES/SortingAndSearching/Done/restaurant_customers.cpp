#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	set<pair<int, int>> restaurant;

	for(int i = 0; i < n; ++i){
		int a, b; cin >> a >> b;

		restaurant.insert(make_pair(a, 1));
		restaurant.insert(make_pair(b, -1));
	}

	long long ans = 0;
	long long curr = 0;
	for(auto [time, op] : restaurant){
		curr += (op == 1);	
		curr -= (op == -1);

		ans = max(ans, curr);
	}

	cout << ans << endl;
	return 0;
}
