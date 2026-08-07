#include <stdio.h>

typedef struct rios{
    int inicio;
    int fim;
    int tempo;
} Rios;

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int cidades_atravessadas[N];
    int menor_tempo = 0;
    Rios rios[M];
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &rios[i].inicio, &rios[i].fim, &rios[i].tempo);
    }
    return 0;
}