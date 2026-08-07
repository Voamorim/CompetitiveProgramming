/*ACEITO*/

#include <stdio.h>

int Rafael (int x, int y){
    return 9*x*x + y*y;
}

int Beto (int x, int y){
    return 2*x*x + 5*5*y*y;
}

int Carlos (int x, int y){
    return -100*x + y*y*y;
}

int main(){
    int casos_teste = 0, resultado = 0;
    int x, y, r, b, c;
    scanf("%d", &casos_teste);
    for(int i = 0; i < casos_teste; i++){
        scanf("%d %d", &x, &y);
        r = Rafael(x, y);
        b = Beto(x, y);
        c = Carlos(x, y);
        if(r > b && r > c){
            printf("Rafael ganhou\n");
        } else if (b > r && b > c){
            printf("Beto ganhou\n");
        } else if (c > r && c > b){
            printf("Carlos ganhou\n");
        }
    }
    return 0;
}