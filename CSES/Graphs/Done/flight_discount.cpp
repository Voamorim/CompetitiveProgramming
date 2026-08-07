#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<long, long>
#define piii pair<long, pair<long, long>>

long long n;

vector<vector<pii>> adj;
vector<vector<long long>> dist;

long long dijkstra(int src){
    priority_queue<piii> pq; // cost, src, used

    dist[src][0] = 0;
    dist[src][1] = 0;

    pq.push({0, {src, 0}});

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();

        if(-curr.F != dist[curr.S.F][curr.S.S]) continue;
        if(curr.S.F == n - 1) break;

        for(auto &v : adj[curr.S.F]){
            // Caso ainda nao tenha sido utilizado o desconto
            if(not curr.S.S){
                long long new_cost = -curr.F + v.S / 2;
                if(new_cost < dist[v.F][1]){
                    dist[v.F][1] = new_cost;
                    pq.push({-new_cost, {v.F, 1}});
                }
            }

            // Caso o desconto nao seja utilizado neste voo
            if(-curr.F + v.S < dist[v.F][curr.S.S]){
                long long new_cost = -curr.F + v.S;
                dist[v.F][curr.S.S] = new_cost;
                pq.push({-new_cost, {v.F, curr.S.S}});
            }
        }
    }

    return dist[n-1][1];
}

signed main(){ _
    long long m; cin >> n >> m;

    adj.resize(n);
    dist.resize(n, vector<long long> (2, LLONG_MAX));

    for(long long i = 0; i < m; ++i){
        long long x, y, z; cin >> x >> y >> z;
        x--, y--;

        adj[x].push_back({y, z});
    }

    long long min_dist = dijkstra(0);

    cout << min_dist << endl;
	return 0;
}
