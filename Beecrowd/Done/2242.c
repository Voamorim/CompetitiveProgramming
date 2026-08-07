/*ACEITO*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*A primeira coisa que ela percebeu é que as consoantes não interferem no quanto as risadas digitais influenciam na transmissão do sentimento*/

/*As risadas digitais mais engraçadas são aquelas em que as sequências de vogais são iguais quando lidas na ordem natural (da esquerda para a direita) ou na ordem inversa (da direita para a esquerda), ignorando as consoantes. Por exemplo, “hahaha” e “huaauhahhuahau” estão entre as risadas mais engraçadas, enquanto “riajkjdhhihhjak” e “huehuehue” não estão entre as mais engraçadas.*/

int main(){
    char risada[51];
    int bol_engracada = 1, bol_quebrou_criterio = 0;    
    scanf("%[^\n]\n", risada);
    int j = strlen(risada) - 1, tam_risada = strlen(risada);
    for(int i = 0; i < tam_risada; i++){
        if(bol_quebrou_criterio) break;
        if(risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u'){
            while(risada[j] != risada[i]){
                if(risada[j] == 'a' || risada[j] == 'e' || risada[j] == 'i' || risada[j] == 'o' || risada[j] == 'u'){
                    bol_quebrou_criterio = 1;
                    break;
                } else {
                    j -= 1;
                }
            }
            j -= 1;
        }
    }

    if(bol_quebrou_criterio){
        bol_engracada = 0;
    }

    if(bol_engracada){
        printf("S\n");
    } else {
        printf("N\n");
    }
    return 0;
}