#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'

// Defines

// Variables

// Functions



int main(){ _
	ll n; cin >> n;
	vector<ll> t(n);
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}	

	// Sorts the coin array
	sort(t.begin(), t.end());

	ll min = 1;
	for(int i = 0; i < n; i++){
		// If the next coin is greater than the minimum sum
		// we cant make atm, so the current sum we cant make is
		// the answer
		if(t[i] > min)
			break;

		min += t[i];
	}

	cout << min << endl;
	return 0;
}
