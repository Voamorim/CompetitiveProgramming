#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(V);

        for (auto& e : edges) {
            int v = e[0];
            int u = e[1];
            int w = e[2];

            graph[v].push_back(make_pair(u, w));
            graph[u].push_back(make_pair(v, w));
        }

        vector<bool> vis(V, false);
        vector<int> dist(V, INT_MAX);

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (pq.size()) {
            auto [d, v] = pq.top();
            pq.pop();

            if (vis[v]) continue;

            vis[v] = true;

            for (auto& [u, w] : graph[v]) {
                dist[u] = min(dist[v] + w, dist[u]);
                pq.push(make_pair(-dist[u], u));
            }
        }

        long long ans = dist[dest] == INT_MAX ? -1 : dist[dest];
        return ans;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1, 1}, {0, 2, 2}, {2, 3, 1}, {1, 2, 1}, {1, 3, 2}};
    int src = 0, dest = 3;
    cout << Solution().shortestPath(V, src, dest, edges) << endl;

    return 0;
}
