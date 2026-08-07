/*ACEITO*/

#include <stdio.h>
#include <string.h>

int main(){
    int N, tam_numero = 0, leds = 0;
    scanf("%d\n", &N);
    char numero[1001];
    for(int i = 0; i < N; i++){
        scanf("%[^\n]\n", numero);
        tam_numero = strlen(numero);
        leds = 0;
        for(int j = 0; j < tam_numero; j++){
            if (numero[j] == '1'){
                leds += 2;
            } else if (numero[j] == '2' || numero[j] == '3' || numero[j] == '5'){
                leds += 5;
            } else if (numero[j] == '4'){
                leds += 4;
            } else if (numero[j] == '6' || numero[j] == '9' || numero[j] == '0'){
                leds += 6;
            } else if (numero[j] == '7'){
                leds += 3;
            } else if (numero[j] == '8'){
                leds += 7;
            }
        }
        printf("%d leds\n", leds);
    }
    return 0;
}