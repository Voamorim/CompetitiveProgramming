#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define F first
#define S second

typedef long long ll;

// Defines

// Variables
int n, d;
vector<pair<int, int>> p;

int done;

// Functions
void soma(){
	for(int i = 0; i < p.size(); i++){
		int np = p[i].F + p[i].S;
		if(np == 0){
			p[i] = {np, +1};
		} else {
			int ant = p[i].S;
			p[i] = {np, ant};
		}
	}

}

void rem(){
	for(int i = 0; i < p.size(); i++){
		if(p[i].F > d and p[i].S == +1){
			p.erase(p.begin() + i);
			i--;
		}
	}
}

int main(){ _
	cin >> n >> d;

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == 0) p.PB({x, +1});
		else p.PB({x, -1});
	}

	while(done != n and p.size()){
		int pref = -1;
		int come = false;

		rem();

		for(int i = 0; i < p.size(); i++){
			if(p[i].F == d){
				if(p[i].S == +1){
					p.erase(p.begin() + i);
					done++;
					come = true;
					break;
				} else {
					pref = i;
				}
			}
		}

		if(!come and pref != -1){
			p.erase(p.begin() + pref);
			done++;
		}

		soma();
	}

	cout << done << endl;

	return 0;
}
