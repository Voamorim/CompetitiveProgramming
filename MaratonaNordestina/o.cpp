#include <bits/stdc++.h>
using namespace std;

#define MAXM 100010
#define MAXC 51

int n, m, c;

// [end_city, seats_used] = revenue
vector<vector<long long>>> dp (MAXM, vector<long long> (MAXC, -LLONG_MAX));

// [end_city] : { {begin_city, price} }
vector<pair<int, int>> passengers (MAXM);

void solve(int src = 1){
	for(int i = 0; i <= m; ++i)
		dp[i][0] = 0;

	for(int city = 1; city <= m; ++city){
		for(int seats = 1; seats <= c; ++ seats){
			dp[city][seats] = max(dp[city][seats], dp[city-1][seats]);


		}


		for(auto &[bc, price] : passengers[city]){	
			for(int seats = 1; seats <= c; ++seats){
				


				dp[city][seats] = max(
			}	
		}	
	}

}

int main(){
	cin >> n >> m >> c;

	for(int i = 0; i < n; ++i){
		int a, b, c; cin >> a >> b >> c;

		passengers[b].push_back(make_pair(a, c));
	}	

	/*

	vector<tuple<int, int, int>> req;
	for(int i = 0; i < n; ++i){
		int a, b, c; cin >> a >> b >> c;

		// {end, begin, price}
		req.push_back(make_tuple(b, a, c));
	}

	sort(req.begin(), req.end());
	*/


	return 0;
} 
