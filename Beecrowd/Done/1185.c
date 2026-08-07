#include <stdio.h>

int main(){
    char operacao; //Soma ou média
    scanf("%c\n", &operacao);
    double matriz[12][12];
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf\n", &matriz[i][j]);
        }
    }

    if(operacao == 'S'){
        double soma = 0;
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < (11 - i); j++){
                soma += matriz[i][j];
            }
        }
        printf("%.1lf\n", soma);
    } else if (operacao == 'M'){
        double media = 0;
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < (11 - i); j++){
                media += matriz[i][j];
            }
        }
        printf("%.1lf\n", media/66);
    }
    return 0;
}