#include <stdio.h>

int main(){
    int linha;
    scanf("%d\n", &linha);
    char operacao; //Soma ou média
    scanf("%c\n", &operacao);
    double matriz[12][12];
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    if(operacao == 'S'){
        double soma = 0;
        for(int i = 0; i < 12; i++){
                soma += matriz[linha][i];
        }
        printf("%.1lf\n", soma);
    } else if (operacao == 'M'){
        double media = 0;
        for(int i = 0; i < 12; i++){
                media += matriz[linha][i];
        }
        printf("%.1lf\n", media/12);
    }
    return 0;
}