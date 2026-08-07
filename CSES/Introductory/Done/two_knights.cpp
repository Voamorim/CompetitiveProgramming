#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

int n;

signed main(){ _
    cin >> n; 

    for(int i = 1; i <= n; ++i){
        ll n_possibilities = (pow(i, 4) - pow(i, 2)) / 2;
        ll n_impossible = 2 * 2 * (i - 2) * (i - 1);

        cout << n_possibilities - n_impossible << endl;
    }

	return 0;
}
