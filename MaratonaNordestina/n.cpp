#include <bits/stdc++.h>
using namespace std;

int main(){
    double N, P; cin >> N >> P;
    P = P / (double) 100.0;

    vector<vector<double>> dp (2028, vector<double> (2028, 0.0));

    for(double n = 2026; n >= 0; --n){
        for(double k = n-1; k >= 0; --k){
            double p = n == 2026 ? 0 : P;

            double a = p * (k / (n + 1.0));
            double b = p * (1.0 - k / (n + 1.0));
            double c = (1.0 - p) * (k / n);
            double d = (1.0 - p) * (1.0 - k / n);

            if(1.0 - c == 0.0) continue;

            dp[n][k] = (1.0 + a * dp[n+1][k] + b * dp[n+1][k+1] + d * dp[n][k+1]) / (1.0 - c);
            dp[n][k] = max(dp[n][k], (double) 0.0);
        }
    }

    cout << fixed << setprecision(7) << dp[N][0] << endl;
    return 0;
}
