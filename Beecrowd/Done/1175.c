#include <stdio.h>

int main (){
    int N[20];
    for (int i = 0; i < 20; i++){
        scanf("%d", &N[i]);
    }
    for (int i = 19, ii = 0; i>= 0; i--, ii++){
        printf("N[%d] = %d\n", ii, N[i]);
    }
    return 0;
}