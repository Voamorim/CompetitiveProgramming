#include <stdio.h>
 
int main() {
    int N, X, Y, soma = 0;
    scanf("%d", &N);
    for (int c = 1; c <= N; c++){
        scanf("%d %d", &X, &Y);
        if (X < Y){
            for (int cc = X + 1; cc < Y; cc++){
                if (cc % 2 == 1){
                    soma += cc;
                }
            }
        } else {
            for (int cc = Y + 1; cc < X; cc++){
                if (cc % 2 == 1){
                    soma += cc;
                }
            }
        }
        printf("%d\n", soma);
        soma = 0;
    }
    return 0;
}