/*ACEITO*/

#include <stdio.h>
#include <math.h>

int main(){
    int largura, altura, profundidade, raio;
    scanf("%d%d%d%d", &largura, &altura, &profundidade, &raio);
    float teste1 = sqrt((largura/2)*(largura/2) + (altura/2)*(altura/2));
    float teste2 = sqrt((altura/2)*(altura/2) + (profundidade/2)*(profundidade/2));
    float teste3 = sqrt((profundidade/2)*(profundidade/2) + (largura/2)*(largura/2));
    if(teste1 > raio || teste2 > raio || teste3 > raio){
        printf("N\n");
    } else {
        printf("S\n");
    }
    return 0;
}