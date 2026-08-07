/*ACEITO*/

#include <stdio.h>
 
int main() {
    int sorteio[6],resultado[6],acertos = 0;
    for(int i = 0; i < 6; i++){
        scanf("%i",&sorteio[i]);
    }
    for(int i = 0; i < 6; i++){
        scanf("%i",&resultado[i]);
    }
    for(int j=0;j<6;j++){
        for(int jj = 0; jj < 6; jj++){
            if(sorteio[j]==resultado[jj]){
                acertos++;
            }
        }
    } 
    if (acertos == 3){
        printf("terno\n");
    } else if (acertos == 4){
        printf("quadra\n");
    } else if (acertos == 5){
        printf("quina\n");
    } else if (acertos == 6){
        printf("sena\n");
    } else if (acertos < 3){
        printf("azar\n");
    }
    return 0;
}