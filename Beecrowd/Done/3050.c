#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    long int maior_distancia_a = 0, maior_distancia_b = 0, atual = 0;
    for(int i = 0; i < N; i++){
        scanf("%ld", &atual);
        if(i <= N/2){
            atual += N - i;
            if(atual > maior_distancia_a){
                maior_distancia_a = atual;
            }
        } else {
            atual += N/2 + i;
        }
    }
    return 0;
}