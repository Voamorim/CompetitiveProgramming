#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();
            ans += pos - 1 - i;
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 10, 4, 2};
    int k = 3;
    cout << Solution().countPairs(arr, k) << endl;
    vector<int> arr2 = {2, 3, 4};
    k = 5;
    cout << Solution().countPairs(arr2, k) << endl;
    return 0;
}
