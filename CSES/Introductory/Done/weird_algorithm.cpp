#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second
typedef long long ll;

int main(){
    ll n; cin >> n;
    while(n != 1){
        cout << n;
        if(n % 2 == 0) n /= 2;
        else n = n*3 + 1;

        
        cout << " ";
    }
    cout << "1" << endl;
    return 0;
}