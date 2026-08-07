#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

// 45 60 60 80
// 30 60 75


int main(){ _
	int n, m, k; cin >> n >> m >> k;
	
	vector<int> a(n); 
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<int> b(m);
	for(int i = 0; i < m; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int i, j; i = j = 0;
	int r = 0;

	while(i < n and j < m){
		if(fabs(a[i] - b[j])  <= k){
			i++; j++;
			r++;
		}
	       	else if(a[i] > b[j]){
			j++;
		} 
		else if(b[j] > a[i]){
			i++;
		}
	}
	cout << r << endl;


	return 0;
}
