/*ACEITO*/

#include <stdio.h>

int main(){
    int N, L, C, total_quebrados = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &L, &C);
        if (L > C){
            total_quebrados += C;
        }
    }
    printf("%d\n", total_quebrados);
    return 0;
}