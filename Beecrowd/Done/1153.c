#include <stdio.h>
 
int main() {
    int N, R;
    scanf("%d", &N);
    R = N;
    for (int c = 1; c < N; c++){
        R *= N - c;
    }
    printf("%d\n", R);
    return 0;
}