/*ACEITO*/

#include <stdio.h>
#include <string.h>

int main(){
    char string[1003];
    int tam_string = 0; int qnt_abertos = 0, qnt_fechados = 0;
    int resultado = 1;
    while(scanf("%s", string) != EOF){
        qnt_abertos = 0; qnt_fechados = 0; resultado = 1;
        tam_string = strlen(string);
        for(int c = 0; c < tam_string; c++){
            if(string[c] == '(') qnt_abertos++;
            if(string[c] == ')') qnt_fechados++;
            if(qnt_fechados > qnt_abertos){
                resultado = 0;
                break;
            }
        }
        if(qnt_abertos != qnt_fechados) resultado = 0;
        if(resultado){
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    return 0;
}