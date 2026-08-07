#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxPathSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        long long asum = 0;
        long long bsum = 0;

        int i = 0;
        int j = 0;

        asum = a[i];
        bsum = b[j];

        long long ans = 0;

        while (i < n and j < m) {
            if (a[i] > b[j]) {
                j += 1;
                if (j < m) bsum += b[j];
            } else if (a[i] < b[j]) {
                i += 1;
                if (i < n) asum += a[i];
            } else if (a[i] == b[j]) {
                ans = ans + max(asum, bsum);
                asum = 0, bsum = 0;
                i += 1, j += 1;

                if (i < n) asum += a[i];
                if (j < m) bsum += b[j];
            }
        }
        i += 1, j += 1;

        while (i < n) {
            asum += a[i];
            i++;
        }
        while (j < m) {
            bsum += b[j];
            j++;
        }

        ans += max(asum, bsum);
        return ans;
    }
};

int main() {
    vector<int> a = {2, 3, 7, 10, 12};
    vector<int> b = {1, 5, 7, 8};

    cout << Solution().maxPathSum(a, b) << endl;

    vector<int> a0 = {1, 2, 3};
    vector<int> b0 = {3, 4, 5};

    cout << Solution().maxPathSum(a0, b0) << endl;
    return 0;
}
