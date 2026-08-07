#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define endl '\n'

// Defines


// Variables
vector<int> v;
vector<ll> ps;
int n;

// Functions
void build(){
    for(int i = 1; i <= n; i++){
        ps[i] = v[i-1] + ps[i-1];
    }
}

ll sum(int l, int r){
    return ps[r] - ps[l];
}

int main(){ _
    int q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.PB(x);
    }
    ps.resize(n+1);
    build();
    while(q--){
        int l, r; cin >> l >> r;
        cout << sum(l, r) << endl;
    }
    return 0;
}
