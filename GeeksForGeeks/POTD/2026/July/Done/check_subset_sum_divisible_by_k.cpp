#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool divisibleByK(vector<int>& arr, int k) {
        for (auto& x : arr) {
            x %= k;
            if (not x) return true;
        }

        vector<bool> sum(k + 1, false);

        sum[0] = true;

        for (auto& x : arr) {
            for (int s = k * 2; s > 0; --s) {
                if (s - x < 0) {
                    continue;
                } else {
                    if (s <= k)
                        sum[s] = sum[s] || sum[s - x];
                    else if (s - x <= k)
                        sum[s % (k + 1)] = sum[s % (k + 1)] || sum[s - x];
                }
            }

            if (sum[k]) return true;
        }

        return false;
    }
};

int main() {
    vector<int> arr = {715, 821, 997, 75, 43, 30, 999, 311, 15, 571, 228};
    int k = 50;
    cout << Solution().divisibleByK(arr, k) << endl;
    vector<int> arrr = {3, 1, 7, 5};
    k = 6;
    cout << Solution().divisibleByK(arrr, k) << endl;
    vector<int> arr0 = {1, 2, 6};
    k = 5;
    cout << Solution().divisibleByK(arr0, k) << endl;
    vector<int> arr1 = {10, 2, 4, 4};
    k = 3;
    cout << Solution().divisibleByK(arr1, k) << endl;
    vector<int> arr2 = {6, 2, 2};
    k = 3;
    cout << Solution().divisibleByK(arr2, k) << endl;

    return 0;
}
