#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

int main(){ _
    int N; cin >> N;
    string mina;
    while(N--){
        cin >> mina;
        int size_mina = size(mina);
        int qnt_abre = 0, diamantes = 0;
        for(int c = 0; c < size_mina; c++){
            if(mina[c] == '<') qnt_abre++;
            if(mina[c] == '>' and qnt_abre){
                qnt_abre--;
                diamantes++;
            }
            
        }
        cout << diamantes << endl;
    }
    return 0;
}