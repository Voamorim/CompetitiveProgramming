/*ACEITO*/

#include <stdio.h>

int main(){
    int R=1 /*Número de rodadas*/;
    int A /*Aldo*/, B /*Beto*/, total_A=0 /*Total de figurinhas viradas por Aldo*/, total_B=0 /*Total de figurinhas viradas por Beto*/;
    int teste = 0;
    while (1){
        scanf("%d", &R);
        teste += 1;
        if (R == 0){
            break;
        }
        for(int i = 0; i < R; i++){
            scanf("%d %d", &A, &B);
            total_A += A;
            total_B += B;
        } 
        printf("Teste %d\n", teste);
        if (total_A > total_B){
            printf("Aldo\n\n");
        } else {
            printf("Beto\n\n");
        }
        total_A = 0;
        total_B = 0;
    }
    return 0;
}