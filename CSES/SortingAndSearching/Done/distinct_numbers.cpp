#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){ _ 
	int n; cin >> n;

	int r = 0;
	set<int> s;



	for(int i = 0; i < n; i++){
		int x; cin >> x;
		s.insert(x);
	}

	cout << s.size() << endl;
	return 0;
}
