#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencheVariaveis(char N1[], char N2[], int n, int m);

int main(){
    int caso_de_teste = 1;
    char N1 [11];
    char N2 [33];
    while (scanf("%s %s", N1, N2) != EOF){
        int i = 0, j = 0, qtde_subsequencias = 0, pos_ultima;
        while(N2[i] != '\0'){
            if (N1[j] == N2[i]){
                while (1){
                    if (N1[j] == '\0'){
                        qtde_subsequencias++;
                        j=0;
                        break;
                    }
                    if (N1[j] == N2[i]){
                        if (j == 0){
                            pos_ultima = i;
                        }
                        j++; 
                        i++;
                    } else if (N1[j] != N2[i]){
                        j = 0;
                        break;
                    }

                }
            } else {
                i++;
            }
        }
        if (qtde_subsequencias == 0){
            printf("Caso #%d:\n"
                   "Nao existe subsequencia\n\n", caso_de_teste);
        } else {
            printf("Caso #%d:\n"
                   "Qtd.Subsequencias: %d\n"
                   "Pos: %d\n\n", caso_de_teste, qtde_subsequencias, (pos_ultima+1));
        }
        caso_de_teste++;
        i = 0;
        j = 0;
    }
    return 0;
}