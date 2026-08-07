#include <stdio.h>
#include <string.h>

int main(){
    //Criando as variáveis
    char frase1 [101];
    char frase2 [101];
    char frase3 [101];
    //Lendo as três frases
    fgets(frase1, sizeof(frase1), stdin);
    fgets(frase2, sizeof(frase2), stdin);
    fgets(frase3, sizeof(frase3), stdin);
    //Removendo os '\n' criados pela função fgets
    frase1[strcspn(frase1, "\n")] = '\0';
    frase2[strcspn(frase2, "\n")] = '\0';
    frase3[strcspn(frase3, "\n")] = '\0';
    //Passo 5
    printf("%s%s%s\n", frase1, frase2, frase3);
    //Passo 6
    printf("%s%s%s\n", frase2, frase3, frase1);
    //Passo 7
    printf("%s%s%s\n", frase3, frase1, frase2);
    //Passo 8
    int i = 0;
    while(frase1[i] != '\0' && i < 10){
        printf("%c", frase1[i]);
        i++;
    }
    i = 0;
    while(frase2[i] != '\0' && i < 10){
        printf("%c", frase2[i]);
        i++;
    }
    i = 0;
    while(frase3[i] != '\0' && i < 10){
        printf("%c", frase3[i]);
        i++;
    }
    printf("\n");
    return 0;
}