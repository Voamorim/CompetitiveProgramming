/*ACEITO*/

#include <stdio.h>
 
int main() {
    int N, V, V_ant = 0, total = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &V);
        if(V != V_ant){
            total += 1;
            V_ant = V;
        }
    }
    printf("%d\n", total);
    return 0;
}