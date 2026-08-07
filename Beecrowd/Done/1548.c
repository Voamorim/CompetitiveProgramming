#include <stdio.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int v[], int e, int d){
    int pivo = v[d];
    int i = e - 1;

    for(int j = e; j < d; j++){
        if(v[j] > pivo){
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
    int n; scanf("%d", &n);
    while(n--){
        int m; scanf("%d", &m);
        int v[m], comp[m];

        for(int i = 0; i < m; i++) {
            int num; scanf("%d", &num);
            v[i] = num; comp[i] = num;
        }

        quickSort(v, 0, m - 1);

        int r = 0;
        for(int i = 0; i < m; i++){
            if(v[i] == comp[i]) r++;
        }
        printf("%d\n", r);
    }    
    return 0;
}