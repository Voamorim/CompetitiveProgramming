/*ACEITO*/

#include <stdio.h>

int main(){
    int N;
    int indice_queda = 0, valores_rpm[100];
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &valores_rpm[i]);
    }
    for(int i = 0; i < N-1; i++){
        if(valores_rpm[i] > valores_rpm[i+1]){
            indice_queda = i + 2;
            break;
        }
    }
    printf("%d\n", indice_queda);
    return 0;
}