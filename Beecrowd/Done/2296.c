/*ACEITO*/

#include <stdio.h>

/*A trilha mais fácil é aquela que, em qualquer um dos sentidos de seu percurso, exige o menor esforço de subida. O esforço de subida é proporcional ao desnível do trecho*/

/*Imprime o identificador i da trilha de menor esforço*/
/*Em caso de empate, imprime a de menor indentificador*/

int main(){
    int N /*Quantidade de trilhas*/, M /*Quantidade de medições*/;
    scanf("%d", &N);
    int esforco[N], esforco_descida = 0;
    int altitudes[N][1000];
    for(int i = 0; i < N; i++){
        M = 0;
        scanf("%d", &M);
        esforco_descida = 0;
        esforco[i] = 0;
        for(int j = 0; j < M; j++){
            scanf("%d", &altitudes[i][j]);
        }

        for(int j = 0; j < M-1; j++){    
            if (altitudes[i][j] < altitudes[i][j+1]){
                esforco[i] += altitudes[i][j+1] - altitudes[i][j];
            }
        }
        for(int j = M-1; j > 1; j--){
            if(altitudes[i][j] < altitudes[i][j-1]){
                esforco_descida += altitudes[i][j-1] - altitudes[i][j];
            }
        }
        if (esforco_descida < esforco[i]){
            esforco[i] = esforco_descida;
        }
    }
    int menor_esforco_indice = 0, menor_esforco = esforco[0];
    for(int i = 0; i < N; i++){
        if (esforco[i] < menor_esforco){
            menor_esforco = esforco[i];
            menor_esforco_indice = i;
        }
    }
    printf("%d\n", menor_esforco_indice+1);
    return 0;
}