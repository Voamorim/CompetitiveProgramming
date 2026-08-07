/*TENTANDO*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
    -> Ler até encontrar uma quebra de linha
        - Quando encontrar, acabou a verificação e começa outra
*/

int main(){
    int numero_verificar;
    
    char genero, prox;
    int calcado_atual = 0;

    int caso = 1;

    int pares_iguais = 0, quant_fem = 0, quant_masc = 0;
    scanf("%d\n", &numero_verificar);
    do{  
        prox = 'x'; 
        while(prox != '\n'){
            scanf("%d %c%c", &calcado_atual, &genero, &prox);
            if(prox == EOF){
                break;
            }
            if(numero_verificar == calcado_atual){
                if(genero == 'F') quant_fem += 1;
                if(genero == 'M') quant_masc += 1;
                pares_iguais += 1;
            } 
        }
        printf("Caso %d:\nPares Iguais: %d\nF: %d\nM: %d\n\n", caso, pares_iguais, quant_fem, quant_masc);
        caso += 1;
        pares_iguais = 0, quant_fem = 0, quant_masc = 0;
        if(prox == EOF){
            break;
        }
        if(prox == '\n') scanf("%d\n", &numero_verificar);
    } while(1);
    return 0;
}