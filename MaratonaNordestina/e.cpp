#include <bits/stdc++.h>
using namespace std;

int ELIMINATE_TLE = 1000;

int n;

int llow, lhigh, rlow, rhigh;
int rest_begin, rest_end;

int res = -1;

char ask(){
	int lsize = lhigh - llow + 1;
	int rsize = rhigh - rlow + 1;

	if(lsize <= 0){
		cout << "! " << rlow << endl; cout.flush();
		exit(0);
	}
	if(rsize <= 0){
		cout << "! " << llow << endl; cout.flush();
		exit(0);
	}

	while(lsize > rsize and ELIMINATE_TLE--){
		lhigh -= 1;
		rlow -= 1;
		rhigh -= 1;
		rest_begin -= 1;

		lsize = lhigh - llow + 1;
		rsize = rhigh - rlow + 1;

		if(lhigh == llow){
			rhigh += 1;
			rest_begin += 1;
			break;
		}	
	}

	while(rsize > lsize and ELIMINATE_TLE--){
		rhigh -= 1;
		rest_begin -= 1;
		
		lsize = lhigh - llow + 1;
		rsize = rhigh - rlow + 1;

		if(rhigh == rlow){
			break;	
		}
	}
	
	int t = (lsize + rsize) / 2; 

	if(t == 0){
		if(lhigh - llow + 1){
			cout << "! " << llow << endl;
		}
		else {
			cout << "! " << rlow << endl;
		}
		exit(0);
	}

	cout << "? " << t;
	for(int i = llow; i <= lhigh; ++i){
		cout << ' ' << i;	
	}

	for(int i = rlow; i <= rhigh; ++i){
		cout << ' ' << i;
	}
	cout << endl; 

	char ans; cin >> ans;

	if(ans == 'D' && (lhigh - llow == 0) && (rhigh - rlow == 0)){
		res = rlow;
		cout << "! " << res << endl;
		exit(0);
	} else if(ans == 'E' && (lhigh - llow == 0) && (rhigh - rlow == 0)){
		res = llow;
		cout << "! " << res << endl;
		exit(0);
	}

	return ans;
}

int main(){
	cin >> n;	

	if(n == 2){
		cout << "? 1 2" << endl;

		char r; cin >> r;
		if(r == 'E') {
			cout << "! 1" << endl;
		}
		else{
		       	cout << "! 2" << endl;
		}
		return 0;
	}


	llow = 1, lhigh = n / 3; 
	rlow = lhigh + 1, rhigh = rlow + (lhigh - llow);
	rest_begin = rhigh + 1, rest_end = n;

	int p = 8;
	while(p--){
		rhigh = min(rhigh, n);

		char c = ask();

		if(c == 'I'){
			llow = rest_begin;
			lhigh = (rest_end - rest_begin) / 3 + llow;

			rlow = lhigh + 1;
			rhigh = (rest_end - rest_begin) / 3 + rlow;

			rest_begin = min(rhigh + 1, n);
			rest_end = min(rest_end, n);
		} else if (c == 'D'){
			rest_end = min(rhigh, n);
			
			llow = rlow;
			lhigh = (rhigh - rlow) / 3 + llow;

			
			rhigh = (lhigh + 1) + (rhigh - rlow) / 3;
			rlow = lhigh + 1;
			
			rest_begin = min(rhigh + 1, n);
		} else if (c == 'E'){
			rlow = llow + (lhigh - llow) / 3 + 1;
			rhigh = rlow + (lhigh - llow) / 3;

			rest_begin = min(rhigh + 1, n);
			rest_end = min(lhigh, n);
			
			llow = llow;
			lhigh = llow + (lhigh - llow) / 3;
		}

		rhigh = min(rhigh, n);
		rest_end = min(rest_end, n);
		rest_begin = min(rest_begin, n);
	}

	cout << "! " << llow << endl;

	return 0;
}
