#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define endl '\n'

// Defines


// Variables


// Functions



int main(){ _
	int n, m; 
	while(cin >> n >> m){
	map<pii, int> mp;
	map<int, int> qnt;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		
		if(auto t = qnt.find(x); t == qnt.end()){
			pii y = {x, 1};
			mp[y] = i;
			qnt[x] = 1;
		} else {
			qnt[x]++;
			pii y = {x, qnt[x]};
			mp[y] = i;
		}	
	}

	int a, b; cin >> b >> a;
	m--;
	pii y = {a, b};
	cout << mp[y];

	while(m--){
		cin >> b >> a;
		y = {a, b};
	
		cout << endl;	
		cout << mp[y];
	}
	cout << endl;
}

    	return 0;
}
