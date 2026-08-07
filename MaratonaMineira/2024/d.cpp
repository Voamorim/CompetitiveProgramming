#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define F first
#define S second

// Defines
#define MAXN 10010

// Variables
int n;
int l;
vector<int> f(MAXN);

// Functions


int main(){ _
	cin >> n >> l;
	
	for(int i = 0; i < n; i++) cin >> f[i];

	sort(f.begin(), f.end(), greater<int>());

	int i = 0;
	int ans = 0;

	while(i < n){
		if(100 - f[i] <= l){
			l -= 100 - f[i];
			ans++;
		}
		i++;
	}	

	cout << ans << endl;

	return 0;
}
