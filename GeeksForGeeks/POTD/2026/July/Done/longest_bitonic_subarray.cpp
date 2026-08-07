#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int bitonic(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;

        int i = 1;
        int curr_len = 1;
        int mode = 1;

        int prev = arr[0];

        while (i < n) {
            for (int j = i; mode == 1; ++j) {
                if (j >= n) {
                    ans = max(curr_len, ans);
                    mode = -1;
                    break;
                }

                int curr = arr[j];

                if (curr >= prev) {
                    curr_len += 1;
                } else {
                    mode = 2;
                    i = j + 1;
                    curr_len += 1;
                }
                prev = curr;
            }

            for (int k = i; mode == 2; ++k) {
                if (k >= n) {
                    ans = max(curr_len, ans);
                    mode = -1;
                    break;
                }
                int curr = arr[k];

                if (curr <= prev) {
                    curr_len += 1;
                } else {
                    mode = 1;
                    prev = arr[i - 1];
                    break;
                }

                prev = curr;
            }
            ans = max(curr_len, ans);

            if (mode == -1) break;

            curr_len = 1;
            mode = 1;

            ans = max(curr_len, ans);
        }
        ans = max(curr_len, ans);

        return ans;
    }
};

int main() {
    vector<int> arrr = {4, 3, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5};
    cout << Solution().bitonic(arrr) << endl;
    vector<int> arr0 = {12, 13, 1, 0, 1, 1, 2, 3, 0, 1, 2, 3, 4};
    cout << Solution().bitonic(arr0) << endl;
    vector<int> arr = {12, 4, 78, 90, 45, 23};
    cout << Solution().bitonic(arr) << endl;
    vector<int> arr2 = {10, 20, 30, 40};
    cout << Solution().bitonic(arr2) << endl;
    vector<int> arr3 = {10, 10, 10, 10};
    cout << Solution().bitonic(arr3) << endl;

    return 0;
}
