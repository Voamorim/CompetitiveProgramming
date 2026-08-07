#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl

typedef long long ll;

//Intervalo de 1 min

int main(){
	int N; cin >> N;
	int k; cin >> k;
	k-=N -1; k /= N;
	cout << k << endl;
	return 0;
}
