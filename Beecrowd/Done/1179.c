#include <stdio.h>

int main (){
    int valor, par[5], impar[5], i = 0, j = 0;
    for (int v = 0; v < 15; v++){
        scanf("%d", &valor);
        if (valor % 2 == 0){
            par[i] = valor;
            i++;
            if (i == 5){
                for (i = 0; i < 5; i++){
                    printf("par[%d] = %d\n", i, par[i]);
                }
                i = 0;
            }
        } else {
            impar[j] = valor;
            j++;
            if (j == 5){
                for (j = 0; j < 5; j++){
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                j = 0;
            }
        }

    }
    for (int l = 0; l < j; l++){
        printf("impar[%d] = %d\n", l, impar[l]);
    }
    for (int k = 0; k < i; k++){
        printf("par[%d] = %d\n", k, par[k]);
    }

    return 0;
}