#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        int ans = 0;

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = 1; i <= n; ++i) {
            dp[i][1] =
                max(dp[i - 1][0] + h[i - 1], max(dp[i - 1][0] + l[i - 1], dp[i - 1][1] + l[i - 1]));

            // no task
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        ans = max(dp[n][0], dp[n][1]);
        return ans;
    }
};

int main() {
    vector<int> h = {2, 8, 1};
    vector<int> l = {1, 2, 1};
    cout << Solution().maxTask(h, l) << endl;

    vector<int> h1 = {3, 6, 8, 7, 6};
    vector<int> l1 = {1, 5, 4, 5, 3};
    cout << Solution().maxTask(h1, l1) << endl;

    return 0;
}
