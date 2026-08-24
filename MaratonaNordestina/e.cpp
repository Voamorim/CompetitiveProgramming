#include <bits/stdc++.h>
using namespace std;

void case2(void);

char ask(int low, int dividing_factor){

	int total = dividing_factor * 2;
	int t = total / 2;

	cout << "? " << t;
	for(int i = low, val = 0; val < dividing_factor * 2; ++val, ++i){
		cout << ' ' << i;	
	}	
	cout << endl;

	char ans; cin >> ans;
	return ans;
}

int main(){
	int n; cin >> n;

	if(n == 2){
		case2();
		return 0;
	}

	int dividing_factor = n/3;
	int low = 1;
	int rlim = n;

	int q = 8;
	while(low < rlim && q--){
		char ans = ask(low, dividing_factor);

		if(ans == 'I'){
			low = low + dividing_factor * 2;
		} else if (ans == 'E'){
			rlim = low + dividing_factor - 1;	
		} else {
			low = low + dividing_factor;
			rlim = low + dividing_factor - 1;
		}
		dividing_factor = ceil((rlim - low + 1) / 3.0);
	}

	cout << "! " << low << endl;
	return 0;
}

void case2(void){
	int low = 1, high = 2;

	char ans = ask(low, 1);	
	if(ans == 'E') cout << "! " << low << endl;
	else cout << "! " << high << endl;

	return;
}
