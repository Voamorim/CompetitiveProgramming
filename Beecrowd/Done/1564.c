#include <stdio.h>

int main(){
    int reclamacoes = 0;
    while(scanf("%d", &reclamacoes) != EOF){
        if(reclamacoes == 0){
            printf("vai ter copa!\n");
        } else{
            printf("vai ter duas!\n");
        }
    }
    return 0;
}