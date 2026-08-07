/*TENTANDO*/

#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(){
    char string[52], caractere, init_seq, fim_seq;
    int letras[26], qnt_letras,fim = 0, maior_indice = 0, indice = 0, fimt = 0;
    while(1){   
        indice = 0;
        string[0] = '\0';
        maior_indice = 0;
        qnt_letras = 0;

        init_seq = '\0'; fim_seq = '\0';
        
        while(1){
            if(scanf("%c", &caractere) == EOF){
                fimt = 1;
                string[indice] = '\0';
                break;
            }
            if(caractere == '\n'){
                string[indice] = caractere;
                indice += 1;
                string[indice] = '\0';
                break;
            }
            if(caractere >= 'a' && caractere <= 'z'){
                string[indice] = caractere;
                indice++;
                qnt_letras++;
                letras[caractere - 'a'] = 1;
                if(caractere - 'a' > maior_indice) maior_indice = caractere - 'a';
            }
        }
        if(qnt_letras == 0){
            printf("\n");
            if(string[0] == '\0')return 0;
        } else {
            int i = 0;
            for(; i < 26; i++){
                if(letras[i]){
                    init_seq = i + 'a';
                    while(1){
                        i++;
                        if(!letras[i] || i > 26){
                            fim_seq = 'a' + i - 1;
                            qnt_letras -= 1;
                            if(i >= maior_indice){
                                if(init_seq != '\0' && fim_seq != '\0')
                                printf("%c:%c", init_seq, fim_seq);
                                fim = 1;
                            } else {
                                printf("%c:%c, ", init_seq, fim_seq);
                            }
                            break;
                        }
                    }
                }
                if(fim) break;
            }
            printf("\n");
        }
        if(fimt) break;
        fim = 0;
        for(int j = 0; j < 26; j++){
            letras[j] = 0;
        }
    }
    return 0;
}