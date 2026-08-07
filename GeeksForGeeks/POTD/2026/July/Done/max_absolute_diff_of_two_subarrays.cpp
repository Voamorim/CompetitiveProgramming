#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int, int>> maxUpTo(n, {INT_MIN, INT_MIN});
        vector<pair<int, int>> minUpTo(n, {INT_MAX, INT_MAX});

        vector<pair<int, int>> maxDownTo(n, {INT_MIN, INT_MIN});
        vector<pair<int, int>> minDownTo(n, {INT_MAX, INT_MAX});

        maxUpTo[0] = {arr[0], arr[0]};
        minUpTo[0] = {arr[0], arr[0]};

        for (int i = 1; i < n; ++i) {
            int prev_max_ans = maxUpTo[i - 1].first;
            int prev_max = maxUpTo[i - 1].second;

            int prev_min_ans = minUpTo[i - 1].first;
            int prev_min = minUpTo[i - 1].second;

            int x = arr[i];

            int curr_max = max(prev_max + x, x);
            int curr_min = min(prev_min + x, x);

            int curr_max_ans = max(curr_max, prev_max_ans);
            int curr_min_ans = min(curr_min, prev_min_ans);

            maxUpTo[i] = {curr_max_ans, curr_max};
            minUpTo[i] = {curr_min_ans, curr_min};
        }

        maxDownTo[n - 1] = {arr[n - 1], arr[n - 1]};
        minDownTo[n - 1] = {arr[n - 1], arr[n - 1]};

        for (int i = n - 2; i >= 0; i--) {
            int prev_max_ans = maxDownTo[i + 1].first;
            int prev_max = maxDownTo[i + 1].second;

            int prev_min_ans = minDownTo[i + 1].first;
            int prev_min = minDownTo[i + 1].second;

            int x = arr[i];

            int curr_max = max(prev_max + x, x);
            int curr_min = min(prev_min + x, x);

            int curr_max_ans = max(curr_max, prev_max_ans);
            int curr_min_ans = min(curr_min, prev_min_ans);

            maxDownTo[i] = {curr_max_ans, curr_max};
            minDownTo[i] = {curr_min_ans, curr_min};
        }

        long long ans = INT_MIN;

        for (int i = 0; i < n - 1; ++i) {
            long long a = abs(maxUpTo[i].first - minDownTo[i + 1].first);
            long long b = abs(minUpTo[i].first - maxDownTo[i + 1].first);

            ans = max(ans, max(a, b));
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << Solution().maxDiffSubArrays(arr) << endl;
    vector<int> arr2 = {2, -1, -2, 1, -4, 2, 8};
    cout << Solution().maxDiffSubArrays(arr2) << endl;

    return 0;
}
