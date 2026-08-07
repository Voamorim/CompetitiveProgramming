#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second
typedef long long ll;

int main(){ _
    int n; cin >> n;
    if(n <= 3 and n!=1) cout << "NO SOLUTION" << endl;
    else if(n == 1) cout << "1" << endl;
    else{
        //Caso n par
        if(n % 2 == 0){
            //Pares
            for(int i = 2; i <= n; i+=2) cout << i << " ";
            //Impares
            for(int i = 1; i < n; i+=2) cout << i << " ";
        } 
        //Caso n impar
        else {
            //Pares
            for(int i = 2; i < n; i+=2) cout << i << " ";
            //Impares
            for(int i = 1; i <= n; i+=2) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}