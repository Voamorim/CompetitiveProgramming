#include <stdio.h>

int main(){
    int idade, cont = 0;
    double media = 0;
    while(scanf("%d", &idade) && idade >= 0){
        media += idade;
        cont++;
    }
    printf("%.2lf\n", media/cont);
    return 0; 
}