#include <bits/stdc++.h>

using namespace std;

string manacher(string& s) {
    // Pre-processamento: tratar palindromos de tam. par
    string arr;
    for (auto& c : s) {
        arr.push_back('#');
        arr.push_back(c);
    }
    arr.push_back('#');

    // dp[i]: maior palindromo centrado em i
    vector<int> dp(arr.size());
    int center = 0, right = 0;

    for (int i = 1; i < arr.size(); ++i) {
        // Utiliza informacao do palindromo espelhado para calcular o tam. min.
        // do palindromo centrado em i
        int mirror = 2 * center - i;
        if (i < right) dp[i] = min(right - i, dp[mirror]);

        // Expande o palindromo em torno do centro
        while (i - dp[i] - 1 >= 0 and i + dp[i] + 1 < arr.size() and
               arr[i - dp[i] - 1] == arr[i + dp[i] + 1])
            dp[i]++;

        if (i + dp[i] > right) {
            center = i;
            right = i + dp[i];
        }
    }

    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    auto it = max_element(dp.begin(), dp.end());
    int max_len = *it, max_center = it - dp.begin();
    string ans;

    for (int i = max_center - max_len; i <= max_center + max_len; ++i) {
        if (arr[i] != '#') ans.push_back(arr[i]);
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    string ans = manacher(s);

    cout << ans << endl;
    return 0;
}
