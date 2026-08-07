/*ACEITO*/

#include <stdio.h>

int main(){
    int P, R;
    char resultado;
    scanf("%d %d", &P, &R);
    if(P == 0){
        resultado = 'C';
    } 
    if( P == 1){
        if(R == 0){
            resultado = 'B';
        } 
        if (R == 1){
            resultado = 'A';
        }
    }
    printf("%c\n",resultado);
    return 0;
}