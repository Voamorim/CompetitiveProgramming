#include <bits/stdc++.h>

using namespace std;

int main(){	
	int n; cin >> n;

	// {end, begin} 
	set<pair<int, int>> movies;

	for(int i = 0; i < n; ++i){
		int begin, end; cin >> begin >> end;	

		movies.insert(make_pair(end, begin));
	}

	auto first_movie = *movies.begin();
	long long curr_time = (first_movie.first);
	long long ans = 1;

	movies.erase(movies.begin());

	for(auto [end, begin] : movies){
		if(curr_time > begin) continue;

		curr_time = end;

		ans += 1;
	}

	cout << ans << endl;
	return 0;
}
