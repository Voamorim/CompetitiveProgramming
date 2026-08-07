/*ACEITO*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d\n", &N);
    char string[1003]; int tam_string = 0;
    for(int caso = 0; caso < N; caso++){
        gets(string);
        tam_string = strlen(string);
        tam_string -= 1;
        
        for(int i = 0; i <= tam_string; i++){
            if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')){
                string[i] += 3;
            }
        }
        
        int add = 0;
        if((float)tam_string/2 > (int)tam_string/2) add = 1;
        else add = 0;

        char aux;
        for(int i = 0, j = tam_string; i < tam_string/2+add && j > tam_string/2-add; i++, j--){
            aux = string[i];
            string[i] = string[j];
            string[j] = aux;
        }
        
        
        for(int i = tam_string/2+add; i <= tam_string; i++){
            string[i] -= 1;
        }
        
        
        printf("%s\n", string);
    }
    return 0;
}