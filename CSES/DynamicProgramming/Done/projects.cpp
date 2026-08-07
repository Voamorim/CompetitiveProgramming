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
map<int, ll> dp;
set<int> s;

signed main(){ _
    cin >> n; 

    vector<piii> events(n); // {fim, inicio, lucro}

    for(int i = 0; i < n; ++i){
        cin >> events[i].S.F >> events[i].F >> events[i].S.S;
    }

    sort(events.begin(), events.end()); 

    int last = 0;

    s.insert(0);
    for(auto p : events){
        // índice do último evento ocorrido
        int i_prev = *s.lower_bound(-p.F);

        // índice do primeiro evento antes do início do evento atual
        int i_prev_start = *s.upper_bound(-p.S.F);

        dp[-p.F] = max(dp[i_prev], dp[i_prev_start] + p.S.S);

        s.insert(-p.F);

        last = max(last, p.F);
    }

    cout << dp[-last] << endl;
	return 0;
}
