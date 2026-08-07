#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back
#define f first
#define s second

typedef long long ll;

// Defines


// Varibles
vector<int> v;

// Functions



int main(){ _
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	for(int i = 0; i < 3; i++){
		int c; cin >> c;
		v.pb(c);
	}

	sort(v.begin(), v.end());

	int min = 0;

	int min_dif = v[1] - v[0] < v[2] - v[1] ? v[1] - v[0] : v[2] - v[1];
	min_dif--;

	int max_dif = v[1] - v[0] > v[2] - v[1] ? v[1] - v[0] : v[2] - v[1];
	max_dif--;

	if(min_dif == 1){
		cout << 1 << endl;
	} else if(max_dif == min_dif and min_dif == 0) cout << 0 << endl;
	else cout << 2 << endl;
	cout << max_dif << endl;


	return 0;
}
