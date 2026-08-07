#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){ _
    int n; cin >> n;

    bool first = true;
    for(int i = 0; i < n; i++){
        string s; cin >> s;

        if(s.size() == 3 and (s[0] == 'O' and s[1] == 'B' or s[0] == 'U' and s[1] == 'R')){
                s[2] = 'I';
        }

        if(first){
            cout << s;
            first = false;
        } else {
            cout << ' ' << s;
        }
    }
    cout << endl;
}
