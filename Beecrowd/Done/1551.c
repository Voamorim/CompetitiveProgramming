/*ACEITO*/

#include <stdio.h>
#include <string.h>

int main(){
    int N, tam_frase = 0, conta_letras = 0;
    int quant_letras[26];
    char frase[1001];
    scanf("%d\n", &N);
    
    /*Inicializa os elementos do vetor com 0*/
    for(int i = 0; i < 26; i++){
        quant_letras[i] = 0;
    }

    for(int i = 0; i < N; i++){
        scanf("%[^\n]\n", &frase);
        for(int j = 0; j < strlen(frase); j++){
            if((frase[j] >= 'a' && frase[j] <= 'z'))
                quant_letras[frase[j] - 'a'] += 1;
        }
        /*Conta a quantidade de letras que apareceram pelo menos uma vez na frase*/
        for(int j = 0; j < 26; j++){
            if(quant_letras[j]){
                conta_letras += 1;
            }
        }

        if (conta_letras == 26){
            printf("frase completa\n");
        } else if (conta_letras >= 13){
            printf("frase quase completa\n");
        } else {
            printf("frase mal elaborada\n");
        }
        conta_letras = 0;
        /*Redefine os elementos do vetor como 0*/
        for(int k = 0; k < 26; k++){
            quant_letras[k] = 0;
        }
    }
    return 0;
}