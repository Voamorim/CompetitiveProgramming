#include <stdio.h>
 
int main() {
    int PA, PB, T, anos = 0;
    scanf("%d", &T); //Numero de casos de teste
    double GA, GB; //taxa de crescimento
    for (int c = 1; c <= T; c++){
        scanf("%d %d %lf %lf", &PA, &PB, &GA, &GB);
        GA /= 100;
        GB /= 100;
        for (int a = 1; a <= 100; a++){
            PA += PA * GA;
            PB += PB * GB;
            if (PA > PB){
                anos = a;
                break;
            }
        }
        if (anos == 0){
            printf("Mais de 1 seculo.\n");
        } else {
            printf("%d anos.\n", anos);
        }
    }
    return 0;
}