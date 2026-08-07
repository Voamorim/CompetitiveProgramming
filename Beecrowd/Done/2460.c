/*FEITO*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



int main(){
    int quant_pessoas_fila = 0;
    scanf("%d", &quant_pessoas_fila);
    int fila[quant_pessoas_fila];
    for(int pessoa = 0; pessoa < quant_pessoas_fila; pessoa += 1){
        scanf("%d", &fila[pessoa]);
    }
    int quant_pessoas_sairam = 0, identificador_pessoa_saiu = 0;
    scanf("%d", &quant_pessoas_sairam);
    for(int pessoa = 0; pessoa < quant_pessoas_sairam; pessoa++){
        scanf("%d", &identificador_pessoa_saiu);
        for(int i = 0; i < quant_pessoas_fila; i++){
            if(identificador_pessoa_saiu == fila[i]){
                fila[i] = -1;
            }
        }
    }
    for(int pessoa = 0; pessoa < quant_pessoas_fila; pessoa ++){
        if(fila[pessoa] >= 1) printf("%d ", fila[pessoa]);
    }
    printf("\n");
    return 0;
}