#include <stdio.h>

int main(){
    int A, B, C, D, aux = 0;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    if(A + B > C && A + C > B && B + C > A)
        aux = 1;
    if(A + B > D && A + D > B && B + D > A)
        aux = 1;
    if(A + D > C && A + C > D && D + C > A)
        aux = 1;
    if(D + B > C && D + C > B && B + C > D)
        aux = 1;
    
    if(aux)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}