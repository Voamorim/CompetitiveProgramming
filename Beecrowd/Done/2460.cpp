#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl

typedef long long ll;

int main(){ _
    int n; cin >> n;
    vector<int> fila(n);
    for(int i = 0; i < n; i++) cin >> fila[i];
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int e; cin >> e;
        for(int j = 0; j < n; j++){
            if(fila[j] == e){
                fila[j] = 0;
                break;
            }
        }
    } 

    int f = 0;

    for(int i = 0; i < n-1; i++){
        if(fila[i]){
            cout << fila[i];
            f = 1;
        }    
        if(fila[i+1] && f) cout << " ";
    }
    if(fila[n-1]) 
        cout << fila[n-1] << endl;
    else cout << endl;
    return 0;
}