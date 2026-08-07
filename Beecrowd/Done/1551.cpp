#include <bits/stdc++.h>

using namespace std;

vector<int> conta_letra(26);

int main(){
    int n;
    scanf("%d\n", &n);

    while(n--){
        string s;
        getline(cin, s);

        for(char c : s){
            if(isalpha(c)){
                conta_letra[c - 'a'] = 1;
            }
        }

        int contador = 0;

        for(auto x : conta_letra){
            contador += x;
        }

        cout << (contador == 26 ? "frase completa" : contador >= 13 ?
                "frase quase completa" : "frase mal elaborada") << endl;

        for(auto &x : conta_letra) x = 0;
    }
    return 0;
}
