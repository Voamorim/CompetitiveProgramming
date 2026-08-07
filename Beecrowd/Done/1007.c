#include <stdio.h>

int main(){
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    int diferenca = (A * B - C * D);
    printf("DIFERENCA = %d\n", diferenca);
    return 0;
}