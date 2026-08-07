/*ACEITO*/

#include <stdio.h>

/*
    O vovô só é cobrado se o saldo for menor que X
    Imprimir o menor saldo da conta
*/

int main(){
    int N_dias, saldo;
    int movimentacao; 
    scanf("%d %d", &N_dias, &saldo);
    int menor_saldo = saldo;
    for(int dia = 0; dia < N_dias; dia++){
        scanf("%d", &movimentacao);
        saldo += movimentacao;
        if(saldo < menor_saldo) menor_saldo = saldo;
    }
    printf("%d\n", menor_saldo);
    return 0;
}