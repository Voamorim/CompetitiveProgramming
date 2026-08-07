/*FEITO*/

#include <stdio.h>

/*
    -> HH:MM (0 ≤ HH < 24, 0 ≤ MM < 60)
*/
/*
int main(){
    int E, V;
    scanf("%d %d", &E, &V);
    int min = 0;
    min = (E / V) * 60;
    min += ((E % V) / (float) V) * 60;
    int hora = (min / 60) + 19;
    if(hora == 24) hora = 0;
    while(hora > 24){
        hora -= 24;
    }
    min = min % 60;
    printf("%02d:%02d\n", hora, min);

    return 0;
}
*/
int main(){
    int E, V;
    scanf("%d %d", &E, &V);
    int min = 0, horas = 0;
    horas = E / V + 19;
    min = ((E % V)/ (double)V) * 60;
    if(horas > 24) horas %= 24;
    printf("%02d:%02d\n", horas, min);
    return 0;
}