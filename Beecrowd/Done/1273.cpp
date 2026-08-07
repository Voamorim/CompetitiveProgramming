#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

int main(){
    int N; int p_linha = 1;
    string palavras[51];
    while(1){
        int maior_p = 0;
        scanf("%d\n", &N);
        if(not N) return 0;
        if(not p_linha) cout << endl;
        for(int i = 0; i < N; i++){
            cin >> palavras[i];
            if(size(palavras[i]) > maior_p) maior_p = size(palavras[i]);
        }   
        for(int i = 0; i < N; i++){
            int size_p = size(palavras[i]);
            while(size_p < maior_p){ cout << " "; size_p++;}
            cout << palavras[i] << endl;
        }
        p_linha = 0;
    }
    return 0;
}