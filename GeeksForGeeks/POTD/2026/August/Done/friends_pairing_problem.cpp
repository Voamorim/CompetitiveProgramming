#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(vector<int>& dp, int n) {
        if (n == 0) return 0;
        if (dp[n]) return dp[n];

        dp[n] = solve(dp, n - 1) + ((n - 1) * solve(dp, n - 2));

        return dp[n];
    }

    int countFriendsPairings(int n) {
        vector<int> dp(20, 0);
        dp[1] = 1;
        dp[2] = 2;

        return solve(dp, n);
    }
};

int main() {
    int n = 3;
    cout << Solution().countFriendsPairings(n) << endl;
    n = 2;
    cout << Solution().countFriendsPairings(n) << endl;
    n = 4;
    cout << Solution().countFriendsPairings(n) << endl;
    n = 5;
    cout << Solution().countFriendsPairings(n) << endl;

    return 0;
}
