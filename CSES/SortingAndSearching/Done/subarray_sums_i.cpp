#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back
#define f first
#define s second

// Defines
#define MAXN 200010

// Variables
int n, target;
vector<int> v(MAXN);

int main(){ _
	cin >> n >> target; 
	for(int i = 1; i <= n; i++) cin >> v[i];

	int r = 0;

	int i = 1, j = 1;
	int sum = v[j];
	while(j <= n){
		if(sum < target){
			j++;
			sum += v[j];
		}
		else if (sum > target){
		       	sum -= v[i];
			i++;
		} else {
			j++;
			sum += v[j];
			r++;
		}
	}
	cout << r << endl;
	

	return 0;
}
