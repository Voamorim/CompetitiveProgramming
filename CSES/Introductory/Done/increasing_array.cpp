#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second
typedef long long ll;

int main(){ _
    int n; cin >> n;
    ll e, past_e;
    ll moves = 0;
    
    cin >> e;
    past_e = e;
    while(--n){
        cin >> e;
        if(e < past_e) {
            moves += past_e - e;
            e += past_e - e;
        }
        past_e = e;
    }
    cout << moves << endl;
    return 0;
}