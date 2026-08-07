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

// Defines



// Variables
bool ans[200020][2];


// Functions
bool operator<(const piii &point, const piii &other){
    if(point.F == other.F) return point.S.F > other.S.F;

    return point.F < other.F;
}



int main(){ _
    int n; cin >> n;
    vector<piii> v(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v[i] = {a, {b, i}};
    }
    sort(v.begin(), v.end());
    set<pii> s;

    for(auto p : v){
        auto found = s.lower_bound({p.S.F, 0});
        if(found != s.end()){
            ans[p.S.S][1] = true;
        }

        s.insert({p.S.F, p.S.S});
    }

    int min_end = INT_MAX;
    for(int i = n - 1; i >= 0; i--){
        auto p = v[i];
        if(p.S.F >= min_end){
            ans[p.S.S][0] = true;
        }
        min_end = min(min_end, p.S.F);
    }

    for(int i = 0; i < n; i++){
        cout << (int)ans[i][0] << ' ';
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << (int)ans[i][1] << ' ';
    }
    cout << endl;
	return 0;
}
