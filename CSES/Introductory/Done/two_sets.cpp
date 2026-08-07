#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

ll sum;
int n; 

int main(){ _
	cin >> n;
	for(int i = 1; i <= n; i++){
		sum += i; 
	}	

	if(sum % 2 == 1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES\n";	


	sum /= 2;
	int t1 = 0, t2 = 0;
	ll sum1 = 0;
	set<int> s;
	for(int i = n; i >= 1; i--){
		if(sum1 + i <= sum){
			s.insert(i);
			sum1 += i;
			t1++;
		}
		
		if(sum1 == sum) break;
	}	

	cout << t1 << endl;
	int aux = 0;
	for(int i = 1; i <= n; i++){
		
		auto b = s.find(i);
		if(b != s.end()){
			aux++;
			if(aux == t1) cout << i << endl;
			else cout << i << ' ';
		}
	}

	t2 = n - t1;
	cout << t2 << endl;
	aux = 0;
	for(int i = 1; i <= n; i++){
		auto b = s.find(i);
		if(b == s.end()){
			aux++;
			if(aux == t2) cout << i << endl;
			else cout << i << ' ';
		}
	}

	return 0;
}
