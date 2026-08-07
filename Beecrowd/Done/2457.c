/*ACEITO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    - Uma palavra é uma sequência de letras consecutivas
    - Um texto é um conjunto de palavras separadas pelo caractere espaço em branco
*/

/*
    -> Dados uma letra e um texto, determine a porcentagem de palavras do texto que contém a letra dada.
*/

int main(){
    char letra, frase[1001];
    int quant_palavras_frase = 1, quant_palavras_com_letra = 0; //Soma em 1 a cada espaço
    int bol_palavra_contabilizada = 0;
    float porcentagem_letra_nas_palavras = 0; //Uma casa decimal (%.1f)

    scanf("%c\n", &letra);
    scanf("%[^\n]\n", frase);

    int tam_frase = strlen(frase);

    for(int i = 0; i < tam_frase; i++){
        if(frase[i] == letra && !bol_palavra_contabilizada){
            quant_palavras_com_letra += 1;
            bol_palavra_contabilizada = 1;
        }
        if (frase[i] == ' '){
            bol_palavra_contabilizada = 0;
            quant_palavras_frase += 1;
        }

    }
    porcentagem_letra_nas_palavras = ((float) quant_palavras_com_letra / quant_palavras_frase) * 100;
    printf("%.1f\n", porcentagem_letra_nas_palavras);

    return 0;
}