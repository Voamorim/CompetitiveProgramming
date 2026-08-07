#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define endl '\n'

// Defines


// Variables


// Functions



int main(){ _
    char a;
    string b;
    
    bool f = false;
    while(1){
        if(f) cout << endl;
        else f = true;

        cin >> a >> b;
        if(a == '0' and b == "0") return 0;

        string aux = ""; 

        bool first = false;
        for(char c : b){
            if(c != a and (c != '0' or first)){
                first = true;
                aux.PB(c);
            }
        }

        if(aux.empty()) cout << '0';
        else{
            cout << aux;
        }
    }
	return 0;
}
