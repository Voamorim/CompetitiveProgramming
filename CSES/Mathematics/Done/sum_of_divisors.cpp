#include <bits/stdc++.h>

using namespace std;

// estrategia:
// contar a quantidade de vezes cada um dos numeros aparece entre os multiplos no intervalo 1,...,n
// essa quantidade é justamente n / i
//
// essa estratégia seria O(n), mas podemos otimizá-la para O(sqrt(n)) ao incrementar a nossa // soma
// para cada um dos "blocos" de vezes que um número aparece
//
// blocos -> faixas de valores até que a divisão n / i seja exata
//
// a soma de cada um dos blocos é a soma de todos os valores de i multiplicados pela divisão
// n / i
//
// para descobrir qual o inicio do próximo "bloco", basta calcular (n / (n / i))  + 1

#define MOD (long long)(1e9 + 7)
#define INV_MOD_2 (long long)500000004  // 2^p-2

inline long long sum(long long a) { return ((a % MOD) * ((a - 1) % MOD) % MOD) * INV_MOD_2 % MOD; }

int main() {
    long long n;
    cin >> n;

    long long ans = 0;

    long long i = 1;
    while (i <= n) {
        long long count = n / i;
        long long j = n / count + 1;
        long long range_sum = (sum(j) - sum(i) + MOD) % MOD;

        ans = (ans + (range_sum * (count % MOD) % MOD)) % MOD;

        i = j;
    }

    cout << ans << endl;

    return 0;
}
