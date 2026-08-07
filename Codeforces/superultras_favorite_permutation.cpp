#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define ii pair<int, int>

// Defines


// Variables


// Funcitions
void solve(){
	int n; cin >> n;
	if(n <= 4){
		cout << -1 << endl;
		return;
	}


	// A estratégia é dividir o vetor em 2 partes:
	// 	1 - Números pares
	// 	2 - Números ímpares
	// É garantido que toda soma de números pares e números ímpares
	// é um número composto (a não ser a soma 1 + 1, que não é possível
	// neste problema). 
	//
	// O ponto de divisão entre a parte dos números pares e ímpares
	// é formado pelos números 4 e 5, os dois menores valores os quais
	// somados não formam um número primo.
	vector<int> v;
	for(int i = 2; i <= n; i+=2){
		if(i == 4) continue;
		
		v.PB(i);
	}
	v.PB(4);
	v.PB(5);
	for(int i = 1; i <= n; i+=2){
		if(i == 5) continue;
		
		v.PB(i);
	}
	
	cout << v[0];
	for(int i = 1; i < n; i++){
		cout << ' ' <<  v[i];
	}	
	cout << endl;

}



int main() { _
	int t; cin >> t;
	while(t--){
		solve();
	}	
	return 0;
}
