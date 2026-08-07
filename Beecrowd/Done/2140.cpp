#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

/*
    Sempre usa duas notas
    Imprime se é possível ou não dar o troco exato
    Notas: 2, 5, 10, 20, 50, 100
*/

int main(){
    int N =1 , M=1;
    int resto, qnt_notas = 0;
    while(1){
        qnt_notas = 0;
        scanf("%d %d", &N , &M);
        if(!N && !M) return 0;
        resto = M - N;
        if(resto >= 100){
            resto -= 100;
            qnt_notas++;
        }
        if(resto >= 100){
            resto -= 100;
            qnt_notas++;
        }
        if(resto >= 50){
            resto -= 50;
            qnt_notas++;
        }
        if(resto >= 50){
            resto -= 50;
            qnt_notas++;
        }
        if(resto >= 20){
            resto -= 20;
            qnt_notas++;
        }
        if(resto >= 20){
            resto -= 20;
            qnt_notas++;
        }
        if(resto >= 10){
            resto -= 10;
            qnt_notas += 1;
        }
        if(resto >= 10){
            resto -= 10;
            qnt_notas += 1;
        }
        if(resto >= 5){
            resto -= 5;
            qnt_notas += 1;
        }
        if(resto >= 5){
            resto -= 5;
            qnt_notas += 1;
        }
        if(resto >= 2){
            resto -= 2;
            qnt_notas++;
        }
        if(resto >= 2){
            resto -= 2;
            qnt_notas++;
        }

        if(qnt_notas == 2 && not resto){
            cout << "possible" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}