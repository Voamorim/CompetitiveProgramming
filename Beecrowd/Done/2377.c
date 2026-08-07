/*ACEITO*/

#include <stdio.h>

int main(){
    int L, D;
    scanf("%d %d", &L, &D);
    int K, P;
    scanf("%d %d", &K, &P);
    int preco_por_km = L * K;
    int pedagio = (L / D) * P;
    printf("%d\n", preco_por_km + pedagio);
    return 0;
}