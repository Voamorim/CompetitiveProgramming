#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return arr[0];

        int ans = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = 1; i <= n; ++i) {
            int j = i - 1;

            dp[i][0] = max(dp[i - 1][0] + arr[j], arr[j]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[j]);
        }

        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[i][0]);
        }
        for (int i = 2; i <= n; ++i) {
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, -4, 5};
    cout << Solution().maxSumSubarray(arr) << endl;
    vector<int> arr0 = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << Solution().maxSumSubarray(arr0) << endl;
    vector<int> arr1 = {-2, -3, -1, -1, -2, -1, -1, -3};
    cout << Solution().maxSumSubarray(arr1) << endl;
    vector<int> arr2 = {-2};
    cout << Solution().maxSumSubarray(arr2) << endl;
    vector<int> arr3 = {-2, -2};
    cout << Solution().maxSumSubarray(arr3) << endl;

    return 0;
}
