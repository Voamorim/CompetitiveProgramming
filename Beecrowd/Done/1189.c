 #include <stdio.h>   
    
int main(){
    char operacao; //Soma ou média
    scanf("%c\n", &operacao);
    double matriz[12][12];
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf\n", &matriz[i][j]);
        }
    }

    double soma = 0;
    for(int i = 1; i < 12; i++){
        for(int j = 0; j < (11 - i); j++){
            if(i > j){
                soma += matriz[i][j];
            }
        }
    }
    if (operacao == 'S'){
        printf("%.1lf\n", soma);
    } else if (operacao == 'M'){
        printf("%.1lf\n", soma/30);
    }
    return 0;
}