#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

string s;
int t;
vector<int> v(26);


int main(){ _
	cin >> s;
	t = s.size();	
	char p[t + 1]; p[t] = '\0'; 

	for(int i = 0; i < t; i++){
		v[s[i]-'A']++;
	}
	
	int qnt_impar = 0; char ci = 0;
	for(int i = 0; i < 26; i++){
		if(v[i] % 2 == 1){
			qnt_impar++;
			ci = i + 'A';
		}
	}

	if(qnt_impar > 1 or (qnt_impar and t%2 == 0)){
		cout << "NO SOLUTION" << endl;
		return 0;
	}

	if(t%2 == 1){
	       	p[t/2] = ci;
		v[ci - 'A'] -= 1;
	}
		
	for(int i = 0, j = t - 1; i < j; i++, j--){
		for(int c = 0; c < 26; c++){
			if(v[c]){
				p[i] = p[j] = c + 'A';
				v[c] -= 2;
				break;
			}
		}
	}

	cout << p << endl;

	return 0;
}
