/*ACEITO*/

#include <stdio.h>
#include <string.h>

/*
    -> Existem letras maiúsculas e minúsculas
    -> Imprimir as letras que mais repetem em ordem alfabética caso haja repetição
    -> Max 200 caracteres
*/

int main(){
    int n_casos = 0;
    scanf("%d\n", &n_casos);

    char frase[201], caractere;
    int tam_frase = 0, i = 0;

    int frequencia[26];
    int maior_frequencia = 0;
    for(int i = 0; i < 26; i++){
        frequencia[i] = 0;
    }

    for(int caso = 0; caso < n_casos; caso++){
        i = 0;
        maior_frequencia = 0;
        for(; i < 26; i++){
            frequencia[i] = 0;
        }
        /*Escaneia a frase*/
        scanf("%[^\n]\n", frase);
        tam_frase = strlen(frase);
        i = 0;
        /*Analisa a frequência*/
        for(; i < tam_frase; i++){
            if(frase[i] <= 'Z' && frase[i] >= 'A'){
                frequencia[frase[i] - 'A'] += 1;
            } else if (frase[i] >= 'a' && frase[i] <= 'z') {
                frequencia[frase[i] - 'a'] += 1;
            }
        }
        i = 0;
        /*Recolhe a letra de maior frequência*/
        for(; i < 26; i++){
            if (frequencia[i] > maior_frequencia){
                maior_frequencia = frequencia[i];
            }
        }
        i = 0;
        /*Imprime as letras de maior frequência*/
        for(; i < 26; i++){
            if(frequencia[i] == maior_frequencia){
                printf("%c", i + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}