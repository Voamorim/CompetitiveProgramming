#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define F first
#define S second

typedef long long ll;

// Defines
#define MAXN 200020

// Variables
int n;
ll ans;
vector<vector<ll>> m(MAXN);

// Functions


int main(){ _
	cin >> n;

	int r = 0, num = 0;

	for(int i = 0; i < n; i++){
		cin >> r >> num;

		m[r].PB(num);
	}

	for(int i = 1; i <= 200010; i++){
		if(!m[i].size()) continue;

		sort(m[i].begin(), m[i].end());
		int x = 0, y = m[i].size() - 1;

		int med = (x+y)/2;

		ll stop = m[i][med];
		for(int j = 0; j <= y; j++){
			ans += fabs(m[i][j] - stop);
		}
	}

	cout << ans << endl;
	return 0;
}
