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

map<string, bool> m;
string s;
int n;

void solve(string str, int i){
    if(i == n){
        m[str] = true;
        return;
    }

    for(int j = i; j < n; ++j){
        swap(str[i], str[j]);

        solve(str, i + 1);

        swap(str[i], str[j]);        
    }
}

signed main(){ _
    cin >> s; 
    n = s.size();

    solve(s, 0);

    cout << m.size() << endl;
    for(auto &[str, x] : m){
        cout << str << endl;
    }
	return 0;
}
