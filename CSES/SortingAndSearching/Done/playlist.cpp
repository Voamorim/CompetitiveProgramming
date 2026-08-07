#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main(){ _
	int n; cin >> n;
	
	set<int> s;
	queue<int> q;
	int maior_seq = 0;

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		
		auto c = s.find(x);
		if(c == s.end()){
			s.insert(x);
			q.push(x);
			if(q.size() > maior_seq) maior_seq = q.size();
		} else {
			int tam = q.size();
			for(int j = 0; j < tam; j++){
				if(q.front() != x){
					s.erase(q.front());
					q.pop();
				} else {
					q.pop();
					q.push(x);
					break;
				}
			}
		}
	}

	cout << maior_seq << endl;
	
	return 0;
}
