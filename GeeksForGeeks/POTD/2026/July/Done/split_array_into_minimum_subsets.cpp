#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ans = 0;

        int prev = -2;
        int i = -1;
        do {
            i++;

            if (i >= arr.size()) break;

            if (arr[i] - prev > 1) {
                ans += 1;
            }

            prev = arr[i];
        } while (1);

        return ans;
    }
};

int main() {
    vector<int> arr = {0, 1, 3, 4, 6, 7};
    cout << Solution().minSubsets(arr) << endl;

    return 0;
}
