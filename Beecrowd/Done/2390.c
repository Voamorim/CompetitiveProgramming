/*ACEITO*/

#include <stdio.h>

int main(){
    int N, i = 0;
    int atual, total = 0, anterior = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &atual);
        if (i != 0){
            if (atual - anterior > 10){
                total += 10;
            } else{
                total += atual - anterior;
            }
        }
        anterior = atual;
    }
    printf("%d\n", total + 10);
    return 0;
}   