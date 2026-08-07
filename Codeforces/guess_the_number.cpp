#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl

typedef long long ll;

int main(){ _
	int num;
	int i = 1, j = 1000000;
	int q = 0;
	while(i < j && q < 25){
		int mid = (i+j+1)/2;		
		cout << mid << endl;
	       	cout << flush;	
		string c; cin >> c;
		if(c == "<"){
			j = mid - 1;
		} else if (c == "<="){
			j = mid;
		} else if (c == ">"){
			i = mid + 1;
		} else if (c == ">="){
			i = mid;
		}
		q++;
	}
	cout << "! " << j << endl;
	cout << flush;

	return 0;
}
