#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int p = 0;

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        p += x;
    }

    int qnt_formas = ceil(p / 6.0);
   
    cout << qnt_formas << ' ' << (qnt_formas * 6 - p) << endl;

    return 0;
}
