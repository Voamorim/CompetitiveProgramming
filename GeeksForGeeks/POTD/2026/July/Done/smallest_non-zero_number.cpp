#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(const vector<int>& arr, const int& x, const int& max_val) {
        long long value = x;
        for (auto& k : arr) {
            value = 2 * value - k;
            if (value < 0) return false;
            if (value > max_val) return true;
        }
        return value;
    }

    int find(vector<int>& arr) {
        int low = 0;
        int max_val = *max_element(arr.begin(), arr.end());
        int high = max_val;

        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(arr, mid, max_val)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {3, 4, 3, 2, 4};
    cout << Solution().find(arr) << endl;

    vector<int> arr2 = {4, 4};
    cout << Solution().find(arr2) << endl;

    return 0;
}
