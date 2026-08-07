#include <stdio.h>

int main(){
    int T, A, B, C, D, E, acertaram = 0;
    scanf("%d %d %d %d %d %d", &T, &A, &B, &C, &D, &E);
    if(A == T)
        acertaram++;
    if(B == T)
        acertaram++;
    if(C == T)
        acertaram++;
    if(D == T)
        acertaram++;
    if(E == T)
        acertaram++;
    printf("%d\n", acertaram);
    return 0;
}