#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define passou cout << "passou\n";
#define pb push_back
typedef long long ll;

int n;
vector<vector<pair<int, ll>>> adj;
vector<bool> vis;
vector<ll> dist;
vector<int> par;

void dijkstra(int src){
    priority_queue<pair<ll, int>> pq;
    dist.assign(n, LLONG_MAX);
    vis.assign(n, false);
    par.assign(n, -1);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto edge : adj[u]){
            int v = edge.first;
            ll w = edge.second;
            if(dist[v] == LLONG_MAX or dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({-dist[v], v});
                par[v] = u;
            }
        } 
    }
}

int main(){
    int m; cin >> n >> m; adj.resize(m+1);
    for(int i = 0; i < m; i++){
        int o, d, pi; cin >> o >> d >> pi; o--, d--;
        adj[o].push_back({d, pi});
        adj[d].push_back({o, pi});
    }
    int s; cin >> s; s--;

    dijkstra(s);

    ll maior = -LLONG_MAX, menor = LLONG_MAX;
    for(int i = 0; i < dist.size(); i++){
        if(i == s) continue;
        if(dist[i] > maior) maior = dist[i];
        if(dist[i] < menor) menor = dist[i];
    }

    cout << maior - menor << endl;
    return 0;
}