#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x; cin >> n >> x;

	set<pair<int, int>> values;

	for(int i = 0; i < n; ++i){
		int k; cin >> k;

		int target = x - k;

		auto r = values.lower_bound(make_pair(target, 0));
		if(r != values.end() and r->first + k == x){
			cout << i + 1 << ' ' << r->second + 1 << endl;	
			return 0;
		}

		values.insert(make_pair(k, i));
	}

	cout << "IMPOSSIBLE" << endl;
	return 0;
}
