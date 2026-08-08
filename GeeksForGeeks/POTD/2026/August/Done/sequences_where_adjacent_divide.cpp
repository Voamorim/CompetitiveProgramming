#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(vector<vector<int>>& dp, int idx, int val, int n, int m) {
        if (idx == n) return 1;
        if (dp[idx][val]) return dp[idx][val];

        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            if (i % val != 0 and val % i != 0) continue;

            ans += solve(dp, idx + 1, i, n, m);
        }
        dp[idx][val] = ans;

        return ans;
    }

    int count(int n, int m) {
        vector<vector<int>> dp(20, vector<int>(20, 0));
        return solve(dp, 0, 1, n, m);
    }
};

int main() {
    int n = 1, m = 10;
    cout << Solution().count(n, m) << endl;
    return 0;
}
