/*ACEITO*/

#include <stdio.h>
#include <math.h>

/*
- Acutângulos -> todos os ângulos internos medem menos de 90°
- Retângulos -> possuem um ângulo interno que mede exatamente 90°
- Obtusângulos -> um ângulo interno que mede mais de 90°

    *Nem sempre é possível formar um triângulo com 3 palitos*

*/

int main(){
    int A, B, C;
    double cos_angulo_1, cos_angulo_2, cos_angulo_3;
    int a1, a2, a3;
    scanf("%d %d %d", &A, &B, &C);
    if(A + B > C){
        if(A + C > B){
            if (B + C > A){
                /*Lei dos Cossenos*/
                cos_angulo_1 = (pow(A,2) + pow(B, 2) - pow(C, 2))/(2*A*B);
                cos_angulo_2 = (pow(A,2) + pow(C, 2) - pow(B,2))/(2*A*C);
                cos_angulo_3 = (pow(B,2) + pow(C,2) - pow(A, 2))/(2*B*C);

                if(cos_angulo_1 == 0 || cos_angulo_2 == 0 || cos_angulo_3 == 0){
                    printf("r\n");
                } else if (cos_angulo_1 < 0 || cos_angulo_2 < 0 || cos_angulo_3 < 0){
                    printf("o\n");
                } else {
                    printf("a\n");
                }
            } else {
                printf("n\n");
            }
        } else {
            printf("n\n");
        }
    } else {
        printf("n\n");
    }
    return 0;
}