#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _  ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;

int main(){ _
	int n; cin >> n;
	int maior = -1;
	int g[n][n];
	pair<int, int> pos;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> g[i][j];
			if(g[i][j] > maior){ 
				maior = g[i][j];
				pos.f = i;
				pos.s = j;
			}
		}
	}
	n -=1;
	if(pos.f == 0 and pos.s == 0){
		cout << 2 << endl;
	} else if (pos.f == n and pos.s == n){
	       cout << 0 << endl;
	} else if (pos.f == n and pos.s == 0){
		cout << 1 << endl;
	} else {
		cout << 3 << endl;
	}
		
	return 0;
}
