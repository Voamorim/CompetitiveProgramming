/*ACEITO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N_casos;
    scanf("%d\n", &N_casos);
    char palavra[10];

    int letras_dois = 0, letras_um = 0;

    for(int caso = 0; caso < N_casos; caso++){
        letras_dois = 0, letras_um = 0;
        scanf("%[^\n]\n", palavra);
        if(strlen(palavra) > 4) printf("3\n");
        else{
            for(int i = 0; i < 3; i++){
                if((palavra[i] == 't' && i == 0) || (palavra[i] == 'w' && i ==1) || (palavra[i] == 'o' && i == 2)){
                    letras_dois += 1;
                }
                if((palavra[i] == 'n' && i == 1)|| (palavra[i] == 'e' && i == 2) || (palavra[i] == 'o' && i == 0)){
                    letras_um += 1;
                }
            }
            if(letras_dois > letras_um) printf("2\n");
            else printf("1\n");
        }
    }
    return 0;
}