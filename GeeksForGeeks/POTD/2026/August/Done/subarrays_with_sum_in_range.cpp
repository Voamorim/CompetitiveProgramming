#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countSubarray(vector<int>& arr, int l, int r) {
        int n = arr.size();

        vector<long long> pf_sum(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            long long value = arr[i - 1];

            pf_sum[i] = pf_sum[i - 1] + value;
        }

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            long long curr_l = pf_sum[i] + l;
            long long curr_r = pf_sum[i] + r;

            int lbound = lower_bound(pf_sum.begin(), pf_sum.end(), curr_l) - pf_sum.begin();
            int rbound = upper_bound(pf_sum.begin(), pf_sum.end(), curr_r) - pf_sum.begin();
            ans += rbound - lbound;
        }

        return ans;
    }
};

int main() {
    int l = 3, r = 8;
    vector<int> arr = {1, 4, 6};
    cout << Solution().countSubarray(arr, l, r) << endl;
    l = 4, r = 13;
    vector<int> arr2 = {2, 3, 5, 8};
    cout << Solution().countSubarray(arr2, l, r) << endl;

    return 0;
}
