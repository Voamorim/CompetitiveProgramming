/*ACEITO*/

#include <stdio.h>

int matriz[4][4];
int movimentos_possiveis[4];

void limpaMatriz(int rows, int cols, int matriz[rows][cols]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = 0;
        }
    }
}

void limpaVetor(int* movimentos_possiveis){
    for(int i = 0; i < 4; i++){
        movimentos_possiveis[i] = 0;
    }
}

int main(){
    int N; int qnts_nao_possiveis = 0; int pula = 0; int espaco = 0;
    scanf("%d", &N);
    while(N--){
        qnts_nao_possiveis = 0; pula = 0; espaco = 0;
        /*Lê todos os blocos*/
        for(int rows = 0; rows < 4; rows++){
            for(int cols = 0; cols < 4; cols++){
                scanf("%d", &matriz[rows][cols]);
            }
        }
        
        for(int rows = 0; rows < 4; rows++){
            for(int cols = 0; cols < 4; cols++){
                /*Se o elemento contém um bloco*/
                if(matriz[rows][cols] == 2048){
                    for(int i = 0; i < 4; i++){
                        movimentos_possiveis[i] = 0;
                    }
                    pula = 1;
                    break;
                }
                
                if(matriz[rows][cols]){
                    if(rows > 0) if (!matriz[rows-1][cols] || matriz[rows-1][cols] == matriz[rows][cols]) movimentos_possiveis[0] = 1;
                    if(rows < 3) if (!matriz[rows+1][cols] || matriz[rows+1][cols] == matriz[rows][cols]) movimentos_possiveis[2] = 1;
                    if(cols > 0) if (!matriz[rows][cols-1] || matriz[rows][cols-1] == matriz[rows][cols]) movimentos_possiveis[3] = 1;
                    if(cols < 3) if (!matriz[rows][cols+1] || matriz[rows][cols+1] == matriz[rows][cols]) movimentos_possiveis[1] = 1;
                }
            }
            if(pula) break;
        }

        /*Impressão*/
        if(movimentos_possiveis[2]){ 
            if(espaco){
                printf(" DOWN");
            } else {
                printf("DOWN");
            }
            espaco = 1;
        }
        else qnts_nao_possiveis++;
        if(movimentos_possiveis[3]){ 
            if(espaco) printf(" LEFT");
            else printf("LEFT");
            espaco = 1;
        }
        else qnts_nao_possiveis++;
        if(movimentos_possiveis[1]){ 
            if (espaco) printf(" RIGHT");
            else printf("RIGHT");
            espaco = 1;
        }
        else qnts_nao_possiveis++;
        if(movimentos_possiveis[0]){ 
            if (espaco) printf(" UP");
            else printf("UP");
            espaco = 1;
        }
        else qnts_nao_possiveis++;

        if(qnts_nao_possiveis == 4) printf("NONE");

        printf("\n");

        limpaVetor(movimentos_possiveis);
        limpaMatriz(4, 4, matriz);
    }
    return 0;
}