#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl

int solve(vector<int> &v, int n){
	int topo = n - 1;
	for(int i = n - 2; i >= 0; i--){
		if(v[i] >= v[i+1]) topo -= 1;
		else break;
	}
	int r = topo;
	for(int i = topo - 1; i >= 0; i--){
		if(v[i] <= v[i+1]) r = i;
		else break;
	}
	return r;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		
		cout <<  solve(v, n) << endl;
	}
	return 0;
}
