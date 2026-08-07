#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

// estrategia:
//
// formula para calcular o numero de divisores de um numero n:
// 	f(n) = (e0 + 1) * (e1 + 1) * ... * (ek + 1)
// sendo ei os expoentes do fatores primos de n
//
// o +1 vem da combinatoria. significa incluir ou nao o primo k (expoente 0)

int countDivisors(int x){
	int divisors = 1;

	for(int i = 2; i * i <= x; ++i){
		if(x % i == 0){
			int e = 0;
			
			do{
				x /= i;
				e++;
			} while (x % i == 0);

			divisors *= e + 1;
		}
	}

	if(x > 1) divisors *= 2;

	return divisors;
}

signed main(){ _
	int n; cin >> n;

	while(n--){
		int x; cin >> x;
		cout << countDivisors(x) << endl;
	}

	return 0;
}
