/*ACEITO*/

#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(){
    int maior_num = 0;
    scanf("%d\n", &maior_num);
    int n1, n2;
    scanf("%d", &n1);
    getchar();
    char operador;
    scanf("%c", &operador);
    getchar();
    scanf("%d\n", &n2);
    if(operador == '+'){
        n1 = n1 + n2;
        if(n1 > maior_num){
            printf("OVERFLOW\n");
            return 0;
        } else {
            printf("OK\n");
        }
    } else {
        n1 *= n2;
        if(n1 > maior_num){
            printf("OVERFLOW\n");
            return 0;
        } else {
            printf("OK\n");
        }
    }
    return 0;
}