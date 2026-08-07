#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<ll>> dp (5001, vector<ll> (5001));

ll solveRecursive(int i, int j){
	if(dp[i][j]){
		return dp[i][j];
	}

	if(j - i == 1){
		dp[i][j] = max(dp[i][i] - dp[j][j], 
			   dp[j][j] - dp[i][i]);	
		return dp[i][j];
	}

	dp[i][j] = max(dp[i][i] - solveRecursive(i+1, j), 
		       dp[j][j] - solveRecursive(i, j - 1));

	return dp[i][j]; 
}

ll solveIteratively(int n){
	for(int i = n - 1; i >= 0; --i){
		for(int j = i + 1; j < n; ++j){
			ll choose_left = dp[i][i] - dp[i+1][j];
			ll choose_right = dp[j][j] - dp[i][j-1];

			dp[i][j] = max(choose_left, choose_right);
		}	
	}

	return dp[0][n-1];
}

int main(){
	int n; cin >> n;

	ll sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> dp[i][i];
		sum += dp[i][i];
	}

	ll ans = (solveIteratively(n) + sum) / 2;
	cout << ans << endl;
	return 0;
}
