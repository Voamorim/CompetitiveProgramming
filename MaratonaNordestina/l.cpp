#include <bits/stdc++.h>
using namespace std;

int main(){
	int x; cin >> x;
	bool ans = ((int) ceil((double) x / 2.0f)) & 1;

	if(ans) cout << "IMPAR" << endl;
	else cout << "PAR" << endl;

	return 0;
}
