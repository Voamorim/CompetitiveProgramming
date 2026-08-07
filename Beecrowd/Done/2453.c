/*ACEITO*/

#include <stdio.h>
#include <string.h>

int main(){
    char frase[1001];
    scanf("%[^\n]\n", frase);
    int cont_par_impar = 0, tam_frase = strlen(frase);
    for(int i = 0; i < tam_frase; i++){
        if (frase[i] == ' '){
            printf("%c", frase[i]);
            cont_par_impar = 0;
        } else {
            if(cont_par_impar % 2 == 1){
                printf("%c", frase[i]);
                cont_par_impar += 1;
            } else {
                cont_par_impar += 1;
            }
        }
        
    }
    printf("\n");
    return 0;
}