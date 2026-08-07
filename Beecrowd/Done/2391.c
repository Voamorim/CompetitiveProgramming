/*ACEITO*/

#include <stdio.h>

/*A diferença entre elementos consecutivos deve ser constante*/

/*Quando não quebrarmos nenhuma vez, a saída será 1*/

/*A saída deverá ser o número mínimo de partes que será necessário quebrar*/

int main(){
    int N; //Número de elementos na sequência
    scanf("%d", &N);
    int elementos[N]; //Vetor que armazena os elementos
    int razao = 0, quant_partes = 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &elementos[i]);
    }

    /*Resolução*/
    
    /*Se houver apenas 1 elemento, a resposta sera 1*/
    if (N == 1){
        printf("%d\n", quant_partes);
    } else {
        razao = elementos[0] - elementos[1];

        /*Se faz o teste para N-1 para não acessar posição indevida na memória*/
        for(int i = 0; i < N-1; i++){
            if(elementos[i] - elementos[i+1] == razao){
                /*Faz nada*/
            } else {
                quant_partes += 1;
                /*Testa se i+2 ainda faz parte do limite do vetor*/
                if(i+2 < N){
                    razao = elementos[i+1] - elementos[i+2];
                }
            }
        }

        printf("%d\n", quant_partes);
    }

    return 0;
}