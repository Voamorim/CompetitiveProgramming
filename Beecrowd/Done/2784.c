#include <stdio.h>

/*
    Cabos transmitem em ambas as direções, ou seja, matriz simétrica
*/

int cabos[1001][1001];
int ilhas[1001];

int main(){
    int N, M;
    int x, y, ping;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &x, &y, &ping);
        cabos[x][y] = ping;
        cabos[y][x] = ping;
    }
    int servidor;
    scanf("%d", &servidor);
    int maior_ping = 0, menor_ping = __INT_MAX__;

    for(int i = 1; i <= N; i++){
        if(cabos[servidor][i] > ilhas[i] && i != servidor){
            ilhas[i] = cabos[servidor][i];
        }
    }

    for(int origem = 1; origem <= N; origem++){
        if(origem != servidor && ilhas[origem]){
            for(int destino = 1; destino <= N; destino++){
                if(cabos[origem][destino] && destino != servidor){
                    if(cabos[origem][destino] + ilhas[origem] < ilhas[destino] || !ilhas[destino]){
                        ilhas[destino] = cabos[origem][destino] + ilhas[origem];
                    } 
                }
            }
        }
    }



    for(int i = 1; i <= N; i++){
        if(i != servidor){
            if(ilhas[i] > maior_ping){ 
                maior_ping = ilhas[i];
            }
            if(ilhas[i] < menor_ping){ 
                menor_ping = ilhas[i];
            }
        }
    }
    printf("%d\n", maior_ping - menor_ping);

    return 0;
}