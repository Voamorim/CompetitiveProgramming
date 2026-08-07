#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back
typedef long long ll;

string s;

bool possible(int d){
    for(int i = d; i < s.length();){
        if(s[i] == 'F' or i == 0) return false;        
        if(s[i] == 'L') i -= 1;
        else{ s[i] = 'F'; i += d; }
    }   
    return true;
}



int main(){ _ 
    int t; cin >> t;

    for(int i = 0; i < t; i++){
        cin >> s;
        s = 'R' + s;
        string x = s;
        int e = 1, d = 2 * 1e5 + 10;
        while(e < d){
            int mid = (e + d)/2;
            if(!possible(mid)){
                e = mid + 1;
            } else {
                d = mid;
            }
            s = x;
        }
        cout << e << endl;
    }

    return 0;
}