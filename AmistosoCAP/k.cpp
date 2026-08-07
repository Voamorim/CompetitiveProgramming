#include <bits/stdc++.h>

using namespace std; 

int main(){
    int n; cin >> n;

    int ans = 0;
    int subiram, desceram; cin >> desceram >> subiram;
    ans += desceram; 

    int total = subiram;

    n -= 1;
    while(n--){
        cin >> desceram >> subiram; 
        
        if(desceram > total) {
            ans += desceram - total;
            total = 0;
        } else {
            total -= desceram;
        }

        total += subiram;
    }

   
    cout << ans << endl; 

    return 0;
}
