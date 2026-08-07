#include <bits/stdc++.h>

using namespace std;

#define MAXN 501
#define dbg(x) cout << #x << " == " << x << endl
#define F first
#define S second

typedef long long ll;

vector<vector<ll>> matriz(MAXN, vector<ll> (MAXN));
vector<vector<bool>> vis(MAXN, vector<bool> (MAXN));

ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

ll n;

bool valid(ll i, ll j){
    return not (i >= n or j >= n or i < 0 or j < 0 or vis[i][j]);
}

signed main(){
    cin >> n;

    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            cin >> matriz[i][j];
        } 
    }

    ll ans = 0;

    priority_queue<tuple<ll, ll, long long>> q;
    q.push(make_tuple(0, 0, 0));

    while(!q.empty()){
        auto [t, i, j] = q.top();
        t = -t;
        q.pop(); 

        if(vis[i][j]) continue;
        vis[i][j] = true;

        if(i == n-1 and j == n-1){
            ans = t;
            break;
        }

        for(ll k = 0; k < 4; ++k){
            ll ni = i + dx[k];
            ll nj = j + dy[k];

            if(not valid(ni, nj)) continue;

            if(ni == n - 1 and nj == n - 1){
                q.push(make_tuple(-t -2, ni, nj));
                continue;
            }

            ll chegada = ((t+1) > matriz[ni][nj] ? (t+1) % matriz[ni][nj] : t+1);
            ll espera = matriz[ni][nj] - chegada;
            ll nt = t + espera;
   
            q.push(make_tuple(-nt, ni, nj));
        }
    }

    cout << ans << endl;

    return 0;
}
