#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

int main(){
    string texto, aux;
    char caractere;
    int N;
    scanf("%d\n", &N);
    while(N--){
        for(int l = 0; ; l++){
            if(scanf("%c", &caractere) == EOF) break;
            if(caractere != '\n'){
                texto.push_back(caractere);
            } else {
                break;
            }
        }
        for(int c = 0; c < size(texto); c++){
            if(texto[c] >= 'A' and texto[c] <= 'Z' or texto[c] >= 'a' and texto[c] <= 'z') texto[c] += 3;
        }
        aux = texto;
        for(int ca = size(texto) -1, ct = 0; ca >= 0; ca--, ct++){
            texto[ct] = aux[ca];
        }
        for(int c = size(texto)/2; c < size(texto); c++){
            texto[c] -= 1;
        }
        texto[size(texto)] = '\0';
        cout << texto << endl;
        texto.clear();
    }
    return 0;
}