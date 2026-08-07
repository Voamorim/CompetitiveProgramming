#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countWays(int n, int sum) {
        vector<vector<int>> ways(sum + 1, vector<int>(n + 1, 0));

        ways[0][0] = 1;

        for (int d = 1; d <= n; ++d) {
            for (int val = sum; val >= 0; val--) {
                for (int num = 9; num >= 0; --num) {
                    if (num == 0 and d == 1) continue;
                    if (val - num < 0) continue;

                    ways[val][d] += ways[val - num][d - 1];
                }
            }
        }

        return ways[sum][n] ? ways[sum][n] : -1;
    }
};

int main() {
    int n, sum;
    n = 2, sum = 2;
    cout << Solution().countWays(n, sum) << endl;
    n = 1, sum = 10;
    cout << Solution().countWays(n, sum) << endl;
    n = 2, sum = 10;
    cout << Solution().countWays(n, sum) << endl;
    n = 2, sum = 17;
    cout << Solution().countWays(n, sum) << endl;
    return 0;
}
