#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct par{
    char nome[25];
    int v;
} Par;

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int v[], int e, int d){
    int pivo = v[d];
    int i = e - 1;

    for(int j = e; j < d; j++){
        if(v[j] < pivo){
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i+1], &v[d]);
    return i + 1;
}

void quickSort(int v[], int e, int d){
    if(e < d){
        int pivo = partition(v, e, d);

        quickSort(v, e, pivo - 1);
        quickSort(v, pivo + 1, d);
    } else return;
}

int main(){
    int n;
    while(1){
        if (scanf("%d", &n) == EOF) break;
        Par matriz[n]; int val[n];
        for(int i = 0; i < n; i++){
            scanf("%s", matriz[i].nome);
            scanf("%d", &val[i]);
            matriz[i].v = val[i];
        }
        quickSort(val, 0, n - 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(val[i] == matriz[j].v){
                    printf("%s", matriz[j].nome);
                    break;
                }
            }

            if(i != n - 1){
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}