#include <stdio.h>

int main(){
    int M, A, B;
    scanf("%d", &M);
    scanf("%d", &A);
    scanf("%d", &B);
    int idade = M - (A + B);
    if(idade >= A && idade >= B)
        printf("%d\n", M - (A + B));
    else if (A >= B) printf("%d\n", A);
    else printf("%d\n", B);
    return 0;
}