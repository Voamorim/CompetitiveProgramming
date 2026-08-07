#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second
typedef long long ll;

int main(){ _
    int n; cin >> n;
    vector<int> conjunto; int elemento;
    for(int i = 0; i < n-1; i++){
        cin >> elemento;
        conjunto.push_back(elemento);
    }
    sort(conjunto.begin(), conjunto.end());
    if(n > 2)
        for(int i = 1; i < n-1; i++){
            if(conjunto[i] - conjunto[i-1] > 1){
                cout << conjunto[i] - 1 << endl;
                return 0;
            } else if (i == n-2) {
                cout << n << endl;
            }
        }
    else{
        if(conjunto[0] == n) cout << "1" << endl;
        else cout << n << endl;
    }
    
    return 0;
}