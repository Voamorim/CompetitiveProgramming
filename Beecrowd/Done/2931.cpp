#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){ _ 
    int c, k;

    while(cin >> c >> k){
        unordered_set<string> combinacoes; 

        while(c--){
            string desejado; cin >> desejado;
            int s; cin >> s;
            
            while(s--){
                string suspeito; cin >> suspeito; 
                string str = desejado + ";" + suspeito;
                combinacoes.insert(str);
            }
        }
        
        while(k--){
            string combinacao; cin >> combinacao;

            if(combinacoes.find(combinacao) == combinacoes.end()){
                cout << "N" << endl;
            } else {
                cout << "Y" << endl;
            }
        }
    }

    return 0;
}
