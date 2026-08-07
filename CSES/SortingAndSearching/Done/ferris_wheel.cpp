#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl

typedef long long ll;

vector<bool>done(300000);

int main(){ _ 
	int n, sum; cin >> n >> sum;

	vector<int> c(n); for(int i = 0; i < n; i++) cin >> c[i];
	sort(c.begin(), c.end());
	
	int r = 0;
	int i = 0, j = n - 1;
	while(i < j){
		if(c[i] + c[j] <= sum){	
			r++;
		
			done[i] = true;
			done[j] = true;
			i++, j--;
		} else {
			j--;
		}
	}

	for(int i = 0; i < n; i++){
		if(!done[i]){ 
			r++;
		}
	}
	
	cout << r << endl;
	return 0;
}
