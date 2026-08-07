#include <stdio.h>

int compare(const void *a, const void *b, int m){
    int *x = (int*) a; int *y = (int*) b;
    int mod_a = *x % m; int mod_b = *y % m;
    if(mod_a > mod_b) return 1;
    else if (mod_a < mod_b) return 0;
    else{
        int a_par = (*x % 2 == 0) ? 1 : 0;
        int b_par = (*y % 2 == 0) ? 1 : 0;
        if(a_par && b_par){
            return *x > *y;
        } else if (!a_par && b_par){
            return 0;
        } else if (a_par && !b_par){
            return 1;
        } else{
            return *x < *y;
        }
    }
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int v[], int e, int d, int m){
    int pivo = v[d];
    int i = e - 1;

    for(int j = e; j < d; j++){
        if(!compare(&v[j], &pivo, m)){
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i+1], &v[d]);
    return i + 1;
}

void quickSort(int v[], int e, int d, int m){
    if(e < d){
        int pivo = partition(v, e, d, m);

        quickSort(v, e, pivo - 1, m);
        quickSort(v, pivo + 1, d, m);
    } else return;
}


int main(){
    int n, m; 
    while(1){
        scanf("%d %d", &n, &m); if(!n && !m){ 
            printf("0 0\n");
            break;
        }
        int v[n+1];
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        quickSort(v, 0, n-1, m);
        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i++){
            printf("%d\n", v[i]);
        }
    }
    
    return 0;
}