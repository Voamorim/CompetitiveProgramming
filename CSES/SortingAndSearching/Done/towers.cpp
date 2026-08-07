#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	multiset<int> ms;

	int x; cin >> x;
	ms.insert(x);
	
	for(int i = 1; i < n; ++i){
		cin >> x;

		auto it = ms.upper_bound(x);

		if(it != ms.end()){
			ms.erase(it);
		}

		ms.insert(x);
	}

	cout << ms.size() << endl;

	return 0;
}
