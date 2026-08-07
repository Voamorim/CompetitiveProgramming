#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
typedef long long ll;

//1 metro/min

#define s second
#define f first


int main(){ _
	int xm, ym, n; cin >> xm >> ym >> n;

	vector<pair<float, float>> j(n);
	for(int l = 0; l < n; l++){
		int x, y, t; cin >> x >> y >> t;
		float dist = sqrt(pow(x - xm, 2) + pow(y - ym, 2));
		float tmp = t - dist;
		j[l] = {tmp, dist};
	}
	vector<int> r;
	for(int l = 0; l < n; l++){
		if(j[l].f  >  0){
			r.push_back(l+1);
		}	
	}	
	if(r.size() == 0) cout << "-1" << endl;
	else{
		for(int i = 0; i < r.size() - 1; i++){
			cout << r[i] << " ";
		}
		cout << r[r.size() - 1] << endl;
	}
	return 0;
}
