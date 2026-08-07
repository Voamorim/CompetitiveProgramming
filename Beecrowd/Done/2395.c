/*ACEITO*/

#include <stdio.h>

int main(){
    int A, B, C;
    int X, Y, Z;
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &X, &Y, &Z);
    if (X < A || Y < B || Z < C){
        printf("0\n");
    } else {
        printf("%d\n", (X/A)*(Y/B)*(Z/C));
    }
}