/*ACEITO*/

#include <stdio.h>

/*É possível modificar dois pinos ao mesmo tempo, de 1 em 1*/

int main(){
    int N /*Número de pinos*/, M /*Altura_pino para abrir a fechadura*/;
    scanf("%d %d", &N, &M);
    int pinos[N], quant_movimentos = 0, quant_pinos_ok = 0, indice = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &pinos[i]);
    }
    while(indice < N){
        while(pinos[indice] < M){
            pinos[indice] += 1;
            pinos[indice+1] += 1;
            quant_movimentos++;
        }
        while(pinos[indice] > M){
            pinos[indice] -= 1;
            pinos[indice+1] -= 1;
            quant_movimentos++;
        }
        indice += 1;
    }
    printf("%d\n", quant_movimentos);
    return 0;
}