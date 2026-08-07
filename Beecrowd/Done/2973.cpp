#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back

typedef long long ll;

int n, c, t;
vector<int> p;

bool possible(ll tmp){
    ll r = tmp*t; int cmp = 1;
    for(int i = 0; i < n; i++){
        if(r >= p[i]) r -= p[i];
        else {
            cmp += 1;
            r = t*tmp;
            i--;
        }
        if(cmp > c) return false;
    }
    return true;
}

int main(){ _ 
    cin >> n >> c >> t;
    p.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int e = 0, d = 1e9+1; 
    while(e < d){
        int mid = (e + d)/2;
        if(!possible(mid)) e = mid + 1;
        else d = mid;
    }
    cout << e << endl;
    return 0; 
}