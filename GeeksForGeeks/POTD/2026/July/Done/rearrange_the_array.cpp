#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int gcd(const int& a, const int& b) { return b == 0 ? a : gcd(b, a % b); }

    int lcm(const int& a, const int& b) { return a * (b / gcd(a, b)); }

    int dfs(const vector<int>& graph, vector<bool>& visited, int v) {
        if (visited[v]) return 0;
        visited[v] = true;
        return 1 + dfs(graph, visited, graph[v]);
    }

    int minOperations(vector<int>& b) {
        for (auto& x : b) x -= 1;
        int n = b.size();

        vector<int> graph(n, 0);

        for (int i = 0; i < n; ++i) {
            graph[i] = b[i];
        }

        vector<bool> visited(n, false);
        vector<int> periods;

        for (int i = 0; i < n; ++i) {
            if (not visited[i]) {
                int p = dfs(graph, visited, i);
                periods.push_back(p);
            }
        }

        int ans = periods[0];
        for (int i = 1; i < periods.size(); ++i) {
            ans = lcm(ans, periods[i]);
        }

        return ans;
    }
};

int main() {
    vector<int> b = {2, 3, 1, 5, 4};
    cout << Solution().minOperations(b) << endl;

    return 0;
}
