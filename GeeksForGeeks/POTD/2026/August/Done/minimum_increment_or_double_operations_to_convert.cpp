#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countMinOperations(vector<int>& arr) {
        int max_div_ops = 0;
        int n_inc_ops = 0;

        for (auto x : arr) {
            if (x == 0) continue;

            int curr_div_ops = 0;
            while (x > 1) {
                if (x & 1) {
                    x -= 1;
                    n_inc_ops += 1;
                }

                x /= 2;
                curr_div_ops += 1;
            }
            n_inc_ops += 1;
            max_div_ops = max(curr_div_ops, max_div_ops);
        }

        return max_div_ops + n_inc_ops;
    }
};

int main() {
    vector<int> arr = {16, 16, 16};
    cout << Solution().countMinOperations(arr) << endl;
    vector<int> arr2 = {2, 3};
    cout << Solution().countMinOperations(arr2) << endl;

    return 0;
}
