#include <stdio.h>
 
int main() {
    int N, A = 0, B = 1, C;
    scanf("%d", &N);
    for (int i = 1; i < N; i++){
        if (i == 1){
            printf("%d ", A);
        }
        printf("%d ", B);
        C = B;
        B = A + B;
        A = C;
    }
    printf("\b\n");
    return 0;
}