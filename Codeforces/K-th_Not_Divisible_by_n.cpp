#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back
typedef long long ll;

int n, k;

int main(){ _
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        if(k < n) cout << k << endl;
        else { 
            ll e = 1, d = INT_MAX;
            ll sol, r;
            while(e <= d){
                ll mid = (e + d)/2;
                sol = mid - (mid / n);
                if(sol > k){
                    d = mid - 1;
                } else if (sol < k) {
                    e = mid + 1;
                } else {
                    r = mid; 
                    d = mid - 1;
                }
            }
            cout << r << endl;
        }
    }
    return 0;
}