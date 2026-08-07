#include <bits/stdc++.h>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define ull unsigned long long

// estrategias utilizadas:
//
// 1- teste de primalidade de miller-rabin
//      todo primo deve seguir a pelo menos um dos dois testes
// para qualquer base:
//      teste 1:
//          base^q mod n == +-1
//      teste 2:
//          base^(2^r * q) mod n == -1
//      caso ambos os testes falhem, o numero e garantidamente
// composto
//
// 2- wheel factorization
//      Todo primo maior que 3 obedece a formula 6k + 1 ou
// 6k + 5. Logo precisamos testar somente os numeros que
// obedecem a esse formato
//
// 3 - testar se o numero tem um dos fatores um dos primos
//     pequenos estabelecidos

vector<ull> small_primes = {2, 3, 5, 7, 11, 13, 17};

ull fastModPow(ull a, ull b, ull mod) {
    ull ans = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) ans = ((__int128_t)ans * a) % mod;
        a = (__int128_t)a * a % mod;
        b /= 2;
    }

    return ans;
}

bool millerRabin(ull n, ull base, ull k, ull q) {
    // Test 1: b^q mod n == +-1
    ull result = fastModPow(base, q, n);
    if (result == 1 or result == n - 1) return true;

    // Test 2: b^(2^r * q) == -1, for r = 1...k-1
    for (int r = 1; r < k; ++r) {
        result = (__int128_t)result * result % n;
        if (result == n - 1) return true;
    }

    return false;
}

bool primalityTest(ull n) {
    // Testa se n e divisivel por um dos fatores primos pequenos
    for (auto& p : small_primes) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }

    // Descobre os valores de k e q
    ull ancestor = n - 1;
    ull k = 0;
    ull q = 0;
    while (ancestor % 2 == 0) {
        ancestor /= 2;
        k += 1;
    }
    q = ancestor;

    bool ans = true;
    for (int i = 0; i < small_primes.size(); ++i) {
        ans &= millerRabin(n, small_primes[i], k, q);

        if (not ans) return false;
    }

    return ans;
}

int main() {
    _

        ull t;
    cin >> t;

    while (t--) {
        ull n;
        cin >> n;
        ull original_val = n;

        if (n < small_primes[small_primes.size() - 1]) {
            auto it = upper_bound(small_primes.begin(), small_primes.end(), n);
            cout << *it << endl;
            continue;
        }

        n += 1;

        if (n % 2 == 0) n++;

        for (ull k = n / 6; true; ++k) {
            ull test1 = 6 * k + 1;
            ull test2 = 6 * k + 5;

            if (test1 > original_val) {
                bool test = primalityTest(test1);
                if (test) {
                    cout << test1 << endl;
                    break;
                }
            }

            if (test2 > original_val) {
                bool test = primalityTest(test2);
                if (test) {
                    cout << test2 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
