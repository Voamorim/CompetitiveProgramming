/*ACEITO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N;
    scanf("%d\n", &N);
    char frase[50], caractere;
    int deslocamento = 0, tam = 0;
    for(int j = 0; j < N; j++){
        for(; tam < 50; tam++){
            scanf("%c", &caractere);
            if (caractere == '\n'){
                break;
            }
            frase[tam] = caractere;
        }
        scanf("%d\n", &deslocamento);
        for(int i = 0; i < tam; i++){
            if (frase[i] - deslocamento >= 65 && frase[i] != '\n'){
                frase[i] = frase[i] - deslocamento;
            } else if (frase[i] != '\n'){
                frase[i] = frase[i] - deslocamento + 26;
            } else{
                break;
            }
        }
        for(int c = 0; c < tam; c++){
            printf("%c", frase[c]);
        }
        printf("\n");
        tam = 0;
    }
    return 0;
}