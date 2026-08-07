#include <bits/stdc++.h>

using namespace std;

void manacher(string& s) {
    // Pre-processamento: tratar palindromos de tam. par
    string arr;
    for (auto& c : s) {
        arr.push_back('#');
        arr.push_back(c);
    }
    arr.push_back('#');

    vector<int> ans(arr.size());

    // dp[i]: maior palindromo centrado em i
    vector<int> dp(arr.size());
    int center = 0, right = 0;

    for (int i = 1; i < arr.size(); ++i) {
        // Utiliza informacao do palindromo espelhado para calcular o tam. min.
        // do palindromo centrado em i
        int mirror = 2 * center - i;
        if (i < right) {
            dp[i] = min(right - i, dp[mirror]);
        }

        // Expande o palindromo em torno do centro
        while (i - dp[i] - 1 >= 0 and i + dp[i] + 1 < arr.size() and
               arr[i - dp[i] - 1] == arr[i + dp[i] + 1]) {
            dp[i]++;
        }

        if (i + dp[i] > right) {
            center = i;
            right = i + dp[i];
        }
    }

    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=

    for (int i = 1; i < arr.size(); ++i) {
        cout << dp[i] << ' ';
        if (dp[i]) {
            int j = i + dp[i] / 2;
            ans[j] = max(ans[j], dp[i]);
        }
    }
    cout << endl << endl;

    for (int i = 0; i < arr.size(); ++i) {
        if (ans[i]) cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    string s;
    cin >> s;

    manacher(s);

    return 0;
}
