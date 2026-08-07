#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxCharGap(string& s) {
        vector<long long> first_ocurr(100, 0);

        long long ans = -1;
        for (int i = 0; i < s.size(); ++i) {
            int k = s[i] - 'a';

            if (not first_ocurr[k]) {
                first_ocurr[k] = i + 1;
                continue;
            }

            ans = max(ans, i - first_ocurr[k]);
        }

        return ans;
    }
};

int main() {
    string s = "socks";
    cout << Solution().maxCharGap(s) << endl;
    return 0;
}
