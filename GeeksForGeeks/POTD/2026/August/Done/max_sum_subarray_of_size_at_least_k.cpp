#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void segtreeBuild(vector<long long>& segtree, vector<long long>& v, int tl, int tr,
                      int node = 1) {
        if (tl == tr) {
            segtree[node] = v[tl];
            return;
        }

        int tmid = tl + (tr - tl) / 2;

        segtreeBuild(segtree, v, tl, tmid, node * 2);
        segtreeBuild(segtree, v, tmid + 1, tr, node * 2 + 1);

        segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
    }

    long long segtreeQuery(vector<long long>& segtree, int l, int r, int tl, int tr, int node = 1) {
        if (l > r) return INT_MIN;
        if (tl > r or tr < l) return INT_MIN;
        if (tl >= l and tr <= r) {
            return segtree[node];
        }

        int tmid = tl + (tr - tl) / 2;
        long long lans = segtreeQuery(segtree, l, r, tl, tmid, node * 2);
        long long rans = segtreeQuery(segtree, l, r, tmid + 1, tr, node * 2 + 1);

        return max(lans, rans);
    }

    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        long long max_sum = 0;

        for (int i = 0; i < k; ++i) {
            max_sum += arr[i];
        }

        long long curr_sum = max_sum;

        vector<long long> ps(n, 0);
        ps[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            ps[i] = ps[i - 1] + arr[i];
        }

        vector<long long> segtree(n * 4, INT_MIN);
        segtreeBuild(segtree, ps, 0, n - 1);

        max_sum = max(curr_sum, max(max_sum, segtreeQuery(segtree, k, n - 1, 0, n - 1)));

        for (int i = k; i < n; ++i) {
            curr_sum -= arr[i - k];
            curr_sum += arr[i];

            max_sum =
                max(curr_sum,
                    max(max_sum, curr_sum + segtreeQuery(segtree, i + 1, n - 1, 0, n - 1) - ps[i]));
        }

        return max_sum;
    }
};

int main() {
    vector<int> arr = {1, -2, 2, -3};
    int k = 3;
    cout << Solution().maxSumWithK(arr, k) << endl;

    vector<int> arr2 = {1, 1, 1, 1, 1, 1};
    k = 2;
    cout << Solution().maxSumWithK(arr2, k) << endl;

    vector<int> arr3 = {-4, -2, 1, -3};
    k = 2;
    cout << Solution().maxSumWithK(arr3, k) << endl;
    return 0;
}
