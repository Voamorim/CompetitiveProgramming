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

int n, k;

vector<int> v;
map<int, int> mp;

signed main(){ _
    cin >> n >> k; 
    
    for(int i = 0; i < k; ++i){
        int x; cin >> x;

        v.PB(x);

        mp[x] += 1;
    }

    cout << mp.size();

    for(int i = k; i < n; ++i){ 
        if(mp[v[i - k]] == 1){
            mp.erase(v[i - k]);
        } else {
            mp[v[i - k]] -= 1;
        }

        int x; cin >> x;
        v.PB(x);

        mp[x] += 1;

        cout << ' ' << mp.size();
    }

    cout << endl;

	return 0;
}
