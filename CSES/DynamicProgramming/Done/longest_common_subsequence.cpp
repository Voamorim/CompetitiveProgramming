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

int n, m;
vector<int> v;
vector<int> w;

vector<int> ans;

int lcs(){
    vector<vector<int>> t(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(v[i-1] == w[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    int i = n, j = m;
    while(i > 0 and j > 0){
        if(t[i][j] == t[i-1][j]){
            i--;
        } else if (t[i][j] == t[i][j-1]){
            j--;
        } else {
            ans.PB(v[i-1]);
            i--; j--;
        }
    }

    reverse(ans.begin(), ans.end());

    return t[n][m];
}

int main(){ _
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        v.PB(x);
    }

    for(int i = 0; i < m; ++i){
        int x; cin >> x;
        w.PB(x);
    }

    cout << lcs() << endl; 
    if(ans.size() >= 1) cout << ans[0]; 
    for(int i = 1; i < ans.size(); ++i){
        cout << ' ' << ans[i];
    }
    cout << endl;
	return 0;
}
