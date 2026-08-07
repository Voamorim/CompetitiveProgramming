#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countKdivPairs(vector<int>& arr, int k) {
        for (auto& x : arr) x %= k;

        long long ans = 0;

        map<int, int> mp;

        for (auto& x : arr) {
            ans += mp[(k - x) % k];
            mp[x] = mp[x] + 1;
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {5, 9, 36, 74, 52, 31, 42};
    int k = 3;

    cout << Solution().countKdivPairs(arr, k) << endl;

    return 0;
}
