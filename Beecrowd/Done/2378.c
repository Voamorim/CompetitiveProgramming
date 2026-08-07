/*ACEITO*/

#include <stdio.h>

int main(){
    int N, capacidade_max, bol = 0;
    scanf("%d %d\n", &N, &capacidade_max);
    int sairam, entraram, total_entraram = 0;
    for(int i = 0; i < N; i++){
        scanf("%d %d\n", &sairam, &entraram);
        total_entraram += entraram - sairam;
        if(total_entraram > capacidade_max){
            bol = 1;
        }
    }
    if(bol == 1){
        printf("S\n");
    } else {
        printf("N\n");
    }
    return 0;
}