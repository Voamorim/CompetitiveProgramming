#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){ _
	int t; cin >> t;
	while(t--){
		ll x, y; cin >> y >> x;

		ll area = 0;
		ll sum = 0;

		if(y > x){
			area = (y-1)*(y-1);
			if(y % 2 != 0){
				sum = x;
			} else {
				sum = (2*y - x);
			}
		} else {
			area = (x-1)*(x-1);
			if(x % 2 == 0){
				sum = y;
			} else {
				sum = (2*x - y);
			}
		}

		cout << area + sum << endl;
	}
	return 0;
}
