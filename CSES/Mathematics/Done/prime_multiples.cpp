#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define MAXK 22

int main() {
    ull n, k;
    cin >> n >> k;

    vector<ull> primes(k);
    for (int i = 0; i < k; ++i) {
        cin >> primes[i];
    }

    ull ans = 0;
    ull ops = 1 << k;

    for (ull bits = 1; bits < ops; ++bits) {
        ull val = 1;

        bool overflow = false;
        for (ull b = 0; b < k; ++b) {
            if (not(bits & (1ULL << b))) continue;

            if (primes[b] > n / val) {
                overflow = true;
                break;
            }

            val *= primes[b];
        }

        if (overflow) continue;

        if (not(__builtin_popcount(bits) & 1ULL)) {
            ans -= n / val;
        } else {
            ans += n / val;
        }
    }

    cout << ans << endl;
    return 0;
}
