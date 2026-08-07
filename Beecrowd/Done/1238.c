/*ACEITO*/

#include <stdio.h>
#include <string.h>

int main(){
    char string_1[51], string_2[51]; char resultado[110]; char caractere = 'x';
    int tam_string1 = 0, tam_string2 = 0;
    int N;
    scanf("%d\n", &N);
    for(int j = 0; j < N; j++){
        int pos = 0;
        while(pos < 50){
            scanf("%c", &caractere);
            if (caractere != ' '){
                string_1[pos] = caractere;
            } else {
                string_1[pos] = '\0';
                break;
            }
            pos += 1;
        }
        pos = 0;
        
        scanf("%s\n", string_2);

        tam_string1 = strlen(string_1);
        tam_string2 = strlen(string_2);
        int i = 0; int indice_str1 = 0, indice_str2 = 0;
        while(1){
            if(indice_str1 >= tam_string1 && indice_str2 >= tam_string2) break;
            
            if(indice_str1 >= tam_string1 && indice_str2 < tam_string2){
                for(; indice_str2 < tam_string2; i++){
                    resultado[i] = string_2[indice_str2];
                    indice_str2 += 1;
                }
                break;
            } else if (indice_str2 >= tam_string2 && indice_str1 < tam_string1){
                for(; indice_str1 < tam_string1; i++){
                    resultado[i] = string_1[indice_str1];
                    indice_str1 += 1;
                }
                break;
            }

            if(indice_str1 < tam_string1 && i % 2 == 0){
                resultado[i] = string_1[indice_str1];
                indice_str1 += 1;
            }
            if(indice_str2 < tam_string2 && i % 2 == 1){
                resultado[i] = string_2[indice_str2];
                indice_str2 += 1;
            }

            i += 1;
        }
        resultado[i] = '\0';
        printf("%s\n", resultado);

        string_1[0] = '\0';
        string_2[0] = '\0';
        resultado[0] = '\0';
    }
    return 0;
}