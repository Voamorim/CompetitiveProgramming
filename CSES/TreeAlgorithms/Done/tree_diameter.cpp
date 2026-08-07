#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n;
vector<vector<int>> graph(MAXN);
vector<bool> vis(MAXN);

int ans = 1;

int dfs(int v = 0) {
    if (vis[v]) return -1;
    vis[v] = true;

    int depth = 0;
    int depth_max1 = INT_MIN, depth_max2 = INT_MIN;

    for (auto& u : graph[v]) {
        depth = dfs(u) + 1;

        if (depth > depth_max1) {
            depth_max2 = depth_max1;
            depth_max1 = depth;
        } else if (depth > depth_max2) {
            depth_max2 = depth;
        }
    }

    if (depth_max1 != INT_MIN) {
        if (depth_max2 != INT_MIN)
            ans = max(depth_max1 + depth_max2 + 1, ans);
        else
            ans = max(depth_max1 + 1, ans);
    }

    return max(depth_max1, depth);
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int src, dest;
        cin >> src >> dest;
        src -= 1, dest -= 1;

        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    for (int i = 0; i < n; ++i) {
        if (not vis[i]) dfs(i);
    }

    cout << ans - 1 << endl;

    return 0;
}
