#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

#define MAXN 110
#define MAXSOMA 10100

int n, total;
vector<int> c(MAXN);

vector<vector<bool>>dp(MAXN, vector<bool> (MAXSOMA));

int main(){ _
	cin >> n;

	for(int i = 1; i <=  n; i++){ 
		cin >> c[i];
		total += c[i];
	}
	
	//Caso o total seja ímpar, não e possível repartir ao meio
	if(total % 2 == 1){
		cout << "-1" << endl;
		return 0;
	}
	total /= 2;

	dp[0][0] = true;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= total; j++){
			dp[i][j] = dp[i-1][j];
			
			if(c[i] <= j && dp[i-1][j - c[i]]){
				dp[i][j] = true;
			}
		}
	}

	//Verifica se é possível repartir os caramelos ao meio, caso contrário, imprime -1
	if(!dp[n][total]){
		cout << "-1" << endl;
		return 0;
	}
		

	// Constroi os caramelos de alice e bob
	vector<int> ali, bob;
	int aux = total;
	for(int i = n; i > 0; i--){
		if(aux >= c[i] && dp[i-1][aux - c[i]]){
			ali.push_back(c[i]);
			aux -= c[i];
		} else {
			bob.push_back(c[i]);
		}
	}

	// Imprime os caramelos na ordem proposta
	int tali = 0, tbob = 0; int p = 0;
	for(int i = 1; i <= n; i++){
		if(tali <= tbob){
			p = ali.back();
			ali.pop_back();
			tali += p;
		}
		else {
			p = bob.back();
			bob.pop_back();
			tbob += p;
		}
		cout << p;
		if(i == n) cout << endl;
		else cout << ' ';
	}
		
	return 0;
}
