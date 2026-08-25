#include <bits/stdc++.h>
using namespace std;

string x;

vector<string> seq = {
	"000", "001", "011", "010", "110", "111", "101", "100"
};

int main(){
	cin >> x;	

	int start = -1;
	for(int i = 0; i < seq.size(); ++i){
		if(x == seq[i]) start = i;
	}

	bool r = 1;
	for(int i = start; 1; i = (i + 1) % seq.size()){
		if(i == start and not r){
			cout << x << endl;
			return 0;
		}
		r = 0;
		cout << seq[i] << endl;
	}
		
	return 0;
}	 
