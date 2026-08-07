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

int n;
ll ans = 0;

signed main(){ _
    cin >> n;

    set<int> s;
    queue<int> q;

    for(int i = 0; i < n; ++i){
        int x; cin >> x;

        if(s.find(x) != s.end()){
            while(q.front() != x){
                s.erase(q.front());
                q.pop(); 
            }
            q.pop();            
        }

        q.push(x);
        s.insert(x);

        ans = ans + q.size();
    }
    
    cout << ans << endl;

	return 0;
}
