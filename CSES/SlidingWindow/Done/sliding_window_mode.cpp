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

set<pair<int, int>> s;
unordered_map<int, int> mp;

signed main(){ _
    cin >> n >> k; 
    vector<int> v(n);

    for(auto& x : v) cin >> x;

    for(int i = 0; i < k; ++i){
        int x = v[i];
        
        int qnt = mp[x];
        if(qnt) s.erase(s.find({qnt, x}));
        s.insert({qnt - 1, x});
        mp[x] -= 1;
    }

    cout << s.lower_bound({-INT_MAX, 0})->S;

    for(int i = k; i < n; ++i){
        auto it = s.find({mp[v[i-k]], v[i-k]});
        pii newp = {it->F + 1, it->S};
        s.erase(it);
        s.insert(newp);
        mp[v[i-k]] += 1; 

        int x = v[i];
        
        int qnt = mp[x];
        if(qnt) s.erase(s.find({qnt, x}));
        s.insert({qnt - 1, x});
        mp[x] -= 1;

        cout << ' ' << s.lower_bound({-INT_MAX, 0})->S;        
    }
    cout << endl;

	return 0;
}
