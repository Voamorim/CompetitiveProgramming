#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;

    vector<vector<double>> dp(n + 1, vector<double>(n * 6 + 10, 0.0f));

    dp[0][0] = 1.0f;

    for (int i = 1; i <= n; ++i) {
        for (int val = 1; val <= 6 * n + 6; ++val) {
            for (int d = 6; d >= 1; --d) {
                if (val - d < 0) continue;

                dp[i][val] += dp[i - 1][val - d] / 6.0f;
            }
        }
    }

    double p = 0.0f;
    for (int i = a; i <= b; ++i) {
        p += dp[n][i];
    }

    cout << fixed << setprecision(6) << p << endl;
    return 0;
}
