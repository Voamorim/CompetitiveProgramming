#include <stdio.h>
 
int main() {
    double f;
    int aux;
    while(scanf("%lf", &f) != EOF){
        printf("NOTAS:\n");
        printf("%d nota(s) de R$ 100.00\n", (int)f/100);
        aux = f / 100;
        f -= aux * 100;
        printf("%d nota(s) de R$ 50.00\n", (int)f/50);
        aux = f / 50;
        f -= aux * 50;
        printf("%d nota(s) de R$ 20.00\n", (int)f/20);
        aux = f / 20;
        f -= aux * 20;
        printf("%d nota(s) de R$ 10.00\n", (int)f/10);
        aux = f / 10;
        f -= aux * 10;
        printf("%d nota(s) de R$ 5.00\n", (int)f/5);
        aux = f / 5;
        f -= aux * 5;
        printf("%d nota(s) de R$ 2.00\n", (int)f/2);
        aux = f / 2;
        f -= aux * 2;
        
        printf("MOEDAS:\n");
        printf("%d moeda(s) de R$ 1.00\n", (int)f/1);
        aux = f / 1;
        f -= aux;
        aux = f / 0.50;
        printf("%d moeda(s) de R$ 0.50\n", aux);
        f -= aux * 0.50;
        aux = f / 0.25;
        printf("%d moeda(s) de R$ 0.25\n", aux);
        f -= aux * 0.25;
        aux = f / 0.1;
        printf("%d moeda(s) de R$ 0.10\n", aux);
        f -= aux * 0.1;
        aux = f / 0.05;
        printf("%d moeda(s) de R$ 0.05\n", aux);
        f -= aux * 0.05;
        aux = f / 0.01;
        printf("%d moeda(s) de R$ 0.01\n", aux);
    }
    return 0;
}