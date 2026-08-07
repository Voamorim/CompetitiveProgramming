#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define t 'a'
#define MAX 27
typedef long long ll;

vector<vector<int>> adj(MAX);
vector<bool> vis(MAX);

vector<pair<int, char>> r;

int n; int v, e; int times = 0;

void dfs(int vr){
    vis[vr] = true;
    char cr = (char) vr + t;
    r.push_back({times, cr});
    for(auto w : adj[vr]){
        if(not vis[w]){ 
            dfs(w); //cout << cr << ",";
        }
    }
}

int main(){
    cin >> n;
    for(int caso = 1; caso <= n; caso++){
        cin >> v >> e;
        adj.resize(v); vis.resize(v);
        for(int i = 0; i < e; i++){
            char o, d; cin >> o >> d;
            adj[o-t].push_back(d-t);
            adj[d-t].push_back(o-t);
        }

        cout << "Case #" << caso << ":" << endl;

        times = 0;
        for(int i = 0; i < v; i++){
            if(!vis[i]) {
                dfs(i);
                times++;
            }
        }
        sort(r.begin(), r.end());
        int atual = 0;
        for(int i = 0; i < v; i++){
            if(r[i].first > atual){
                cout << endl; atual = r[i].first;
            }
            cout << r[i].second << ",";
        }
        cout << endl;
        cout << times << " connected components" << endl << endl;
        adj.clear(); vis.clear(); r.clear();
    }
    return 0;
}