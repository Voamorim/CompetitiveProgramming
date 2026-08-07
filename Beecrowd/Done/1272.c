/*ACEITO*/

#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%d\n", &N);
    char codigo[51], saida[51], caractere;
    int tam_codigo = 0, tam_saida = 0, i = 0;
    for(int caso = 0; caso < N; caso++){
        i = 0;
        tam_saida = 0;
        saida[tam_saida] = '\0';
        
        for(int j = 0; j < 51; j++){
            scanf("%c", &caractere);
            if(caractere != '\n'){
                codigo[j] = caractere;
            } else {
                codigo[j] = '\0';
                break;
            }
        }


        tam_codigo = strlen(codigo);
        if(codigo[0] != ' ' && codigo[0] != '\0'){
            saida[tam_saida] = codigo[0];
            tam_saida += 1;
        } else {
            for(; i < tam_codigo; i++){
                if(codigo[i] != ' '){
                    saida[tam_saida] = codigo[i];
                    tam_saida += 1;
                    break;
                }
            }
        }
        for(; i < tam_codigo; i++){
            if(codigo[i] == ' '){
                if(i + 1 < tam_codigo){
                    if(codigo[i+1] != ' '){
                        saida[tam_saida] = codigo[i+1];
                        tam_saida += 1;
                    }
                }
            }
        }
        saida[tam_saida] = '\0';
        printf("%s\n", saida);
    }
    return 0;
}