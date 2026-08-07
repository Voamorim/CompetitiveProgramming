#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // calcula longest increasing subsequence (lis)
    // resposta e o tamanho da lis - tamanho original do array
    int minDeletions(vector<int>& arr) {
        vector<int> values;

        for (auto& x : arr) {
            if (values.empty() or x > values[values.size() - 1]) {
                values.push_back(x);
            } else {
                auto it = lower_bound(values.begin(), values.end(), x);
                *it = x;
            }
        }

        return arr.size() - values.size();
    }
};

int main() {
    vector<int> arr = {5, 6, 1, 7, 4};
    cout << Solution().minDeletions(arr) << endl;
    vector<int> arr2 = {1, 1, 1};
    cout << Solution().minDeletions(arr2) << endl;
    vector<int> arr3 = {6, 1, 2, 3};
    cout << Solution().minDeletions(arr3) << endl;

    return 0;
}
