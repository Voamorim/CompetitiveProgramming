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
int n;
vector<char> v;

// Functions


int main(){ _
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> n;
    v.resize(n);

    int hr = 0, pr = 0, sr = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i]; char c = v[i];
        if(c == 'H'){
            hr++;
        } else if (c == 'P'){
            pr++;
        } else {
            sr++;
        }
    }

    int ans = 0;
    int hl = 0, pl = 0, sl = 0;

    for(auto c : v){
        if(c == 'H'){
            hr--, hl++;
        } else if(c == 'P'){
            pr--, pl++;
        } else {
           sr--, sl++;
        }
        int maxleft = max(hl, max(sl, pl));
        int maxright = max(hr, max(sr, pr));
        ans = max(ans, maxleft + maxright);
    }
    cout << ans << endl;
    return 0;
}
