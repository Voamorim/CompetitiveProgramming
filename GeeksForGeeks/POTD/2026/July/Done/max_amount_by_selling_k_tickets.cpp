#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxAmount(vector<int>& arr, int k) {
        const long long mod = 1000000000 + 7;

        sort(arr.begin(), arr.end(), greater<int>());
        int n = arr.size();

        long long ans = 0;
        int i = 0;
        int tickets = 0;

        int lwindow = 0;

        while (i < n) {
            ans = (ans + arr[i]) % mod;

            arr[i] -= 1;
            tickets++;

            if (tickets == k) break;

            if (i + 1 == n) {
                if (arr[lwindow] >= arr[i]) {
                    i = lwindow;
                }

                if (not arr[i]) return ans;

                continue;
            }

            if (arr[i] < arr[i + 1]) {
                i += 1;
                continue;
            }

            if (arr[lwindow] >= arr[i]) {
                i = lwindow;
                continue;
            }

            // continua onde esta
            if (i + 1 == n or arr[i] > arr[i + 1]) {
                continue;
            }
        }

        return ans;
    }
};

int main() {
    // vector<int> arr0 = {11, 7, 14, 11, 11};
    // int k = 16;
    // cout << Solution().maxAmount(arr0, k) << endl;

    vector<int> arr1 = {8, 3, 7, 9};
    int k = 38;
    cout << Solution().maxAmount(arr1, k) << endl;

    // vector<int> arr = {4, 3, 6, 2, 4};
    // k = 3;
    // cout << Solution().maxAmount(arr, k) << endl;

    // vector<int> arr2 = {5, 3, 5, 2, 4, 4};
    // k = 2;
    // cout << Solution().maxAmount(arr2, k) << endl;
    return 0;
}
