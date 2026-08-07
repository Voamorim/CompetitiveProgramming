/*ACEITO*/

#include <stdio.h>

int main(){
    int pedras = 0, sapos = 0;
    scanf("%d %d", &pedras, &sapos);
    int posicao_inicial[sapos], distancia_pulo[sapos], pedras_pode_sapo[pedras];
    for(int i = 0; i < pedras; i++){
        pedras_pode_sapo[i] = 0;
    }
    for(int i = 0; i < sapos; i++){
        scanf("%d %d", &posicao_inicial[i], &distancia_pulo[i]);
        for(; posicao_inicial[i] >= 1; posicao_inicial[i] -= distancia_pulo[i]){
            /*Faz nada*/
        }
        posicao_inicial[i] += distancia_pulo[i];
    }
    for(int i = 0; i < sapos; i++){
        for(; posicao_inicial[i] <= pedras; posicao_inicial[i] += distancia_pulo[i]){
            pedras_pode_sapo[posicao_inicial[i]-1] = 1;
        }
    }

    for(int i = 0; i < pedras; i++){
        printf("%d\n", pedras_pode_sapo[i]);
    }

    return 0;
}