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

#define MAXN 200010

int n;
vector<vector<int>> t(MAXN);
vector<int> ans(MAXN);

int count(int e){
    for(int i = 0; i < t[e].size(); ++i){
        int s = t[e][i];
        ans[e] += count(s) + 1; 
    }
    return ans[e];
}

int main(){ _
    cin >> n; 

    for(int i = 2; i <= n; ++i){
        int x; cin >> x;

        t[x].PB(i);
    }

    count(1); 

    cout << ans[1];
    for(int i = 2; i <= n; ++i){
        cout << ' ' << ans[i]; 
    }
    cout << endl;

	return 0;
}
