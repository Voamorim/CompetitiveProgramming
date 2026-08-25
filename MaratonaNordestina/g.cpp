#include <bits/stdc++.h>
using namespace std;

int q;

int main(){
	cin >> q;	

	deque<char> dq;
     	int altos = 0, bahia = 0;

	long long ans = 0;

	while(q--){
		int t; cin >> t;
		
		switch(t){
            char c;
			case 1:
				cin >> c;
				dq.push_back(c);

				if(c == 'A'){
					altos += 1;
				} else {
					bahia += 1;
					ans += altos;
				}
				break;
			case 2:
				cin >> c;
				dq.push_front(c);

				if(c == 'B'){
					bahia += 1;
				} else {
					altos += 1;
					ans += bahia;
				}
				break;
			case 3: 
				c = *dq.rbegin();
				dq.pop_back();
		
				if(c == 'B'){
					ans -= altos;
					bahia -= 1;
				} else {
					altos -= 1;
				}

				break;
			case 4:
				c = *dq.begin();
				dq.pop_front();

				if(c == 'A'){
					ans -= bahia;
					altos -= 1;
				} else {
					bahia -= 1;
				}
				break;
		}

		cout << ans << endl;
	}		
	
	return 0;
}
