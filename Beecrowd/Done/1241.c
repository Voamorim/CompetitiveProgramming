/*ACEITO*/

#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%d\n", &N);
    char numero1[1001], numero2[1001];
    numero1[0] = '\0', numero2[0] = '\0';
    int tam_n1 = 0, tam_n2 = 0;
    int bol_encaixa = 1;
    for(int i = 0; i < N; i++){
        for(;; tam_n1 += 1){
            scanf("%c", &numero1[tam_n1]);
            if(numero1[tam_n1] == ' ' || numero1[tam_n1] == '\n'){
                numero1[tam_n1] = '\0';
                break;
            }
        }
        for(;; tam_n2 += 1){
            scanf("%c", &numero2[tam_n2]);
            if(numero2[tam_n2] == ' ' || numero2[tam_n2] == '\n'){
                numero2[tam_n2] = '\0';
                break;
            }
        }
        if(tam_n2 > tam_n1){
            bol_encaixa = 0;
        } else {
            for(int j = tam_n1 - 1, k = tam_n2 - 1; k >= 0; j--, k--){
                if(numero1[j] != numero2[k]){
                    bol_encaixa = 0;
                    break;
                }
            }
        }
        if(bol_encaixa){
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
            bol_encaixa = 1;
        }
        tam_n1 = 0;
        tam_n2 = 0;

    }
    return 0;
}