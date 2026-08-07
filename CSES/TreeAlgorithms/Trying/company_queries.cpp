#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q; cin >> n >> q;

	vector<int> parent (n + 1);

	parent[1] = -1;

	for(int i = 1; i <= n; ++i){
		cin >> parent[i];
	}

	int Log = ceil(log2(n));

	vector<vector<int>> binary_lift (n + 1, Log + 1);

	for(int v = 1; v <= n; ++v){
		for(int j = 1; j <= Log; ++j){
			binary_lift[v][j] = binary_lift[binary_lift[v][j-1]][j-1];
		}
	}	

	return 0;
}
