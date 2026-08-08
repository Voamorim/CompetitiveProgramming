#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<vector<int>>& graph, vector<bool>& vis, int src) {
        if (vis[src]) return;

        vis[src] = true;

        for (auto& u : graph[src]) {
            dfs(graph, vis, u);
        }
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) return -1;

        int m = edges.size();
        int ans = 0;

        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(graph, vis, i);
                components += 1;
            }
        }

        ans = components - 1;

        return ans;
    }
};

int main() { return 0; }
