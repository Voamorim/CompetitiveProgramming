#include <stdio.h>

int main(){
    int qnt_termos = 0, qnt_casos_teste = 0;
    scanf("%d", &qnt_casos_teste);
    for(int i = 0; i < qnt_casos_teste; i++){
        scanf("%d",&qnt_termos);
        if(qnt_termos % 2 == 0){
            printf("0\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}