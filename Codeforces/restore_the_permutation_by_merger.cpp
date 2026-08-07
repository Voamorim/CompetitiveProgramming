#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set<int> s;
		for(int i = 0; i < 2*n; i++){
			int num; cin >> num;
			auto r = s.insert(num);
			if(!r.second && i < 2*n - 1) cout << num << " ";
		        else if (!r.second) cout << num << endl;	
		}
	}
	return 0;
}
