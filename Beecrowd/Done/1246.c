/*Tentando*/
/*Falta fazer para vários casos de teste*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vaga{
    int comprimento;
    int placa;
    bool ocupada;
    struct vaga* proxima_vaga;
    struct vaga* vaga_anterior;
} Vaga;

typedef struct estacionamento{
    int comprimento;
    Vaga* inicio;
} Estacionamento;

void alocaEstacionamento(Estacionamento *estacionamento){
    /*Cria uma vaga base para necessitar de menos verificações*/
    Vaga* vaga_base = (Vaga*)malloc(sizeof(Vaga));
    estacionamento->inicio = vaga_base;
    estacionamento->inicio->comprimento = 0; estacionamento->inicio->ocupada = true;
    estacionamento->inicio->vaga_anterior = NULL; estacionamento->inicio->placa = 0;
    /*Cria uma vaga inicial que começa com todo o espaço disponível no estacionamento*/
    Vaga* vaga_inicial = (Vaga*)malloc(sizeof(Vaga));
    estacionamento->inicio->proxima_vaga = vaga_inicial; estacionamento->inicio->placa = 0;
    estacionamento->inicio->proxima_vaga->vaga_anterior = vaga_base;
    estacionamento->inicio->proxima_vaga->proxima_vaga = NULL;
    estacionamento->inicio->proxima_vaga->comprimento = estacionamento->comprimento;
    estacionamento->inicio->proxima_vaga->ocupada = false;
}

int ocupaNovaVaga(Estacionamento *estacionamento, int comprimento_estacionar, int placa){
    Vaga *aux_vaga; //Aux vaga percorre todas as vagas do estacionamento
    aux_vaga = estacionamento->inicio;
    while(aux_vaga->proxima_vaga){
        aux_vaga = aux_vaga->proxima_vaga;
        if(aux_vaga->comprimento >= comprimento_estacionar && !aux_vaga->ocupada){
            aux_vaga->ocupada = true;
            if(aux_vaga->comprimento > comprimento_estacionar){
                int espaco_sobrando = aux_vaga->comprimento - comprimento_estacionar;
                Vaga* nova_vaga = (Vaga*)malloc(sizeof(Vaga));
                nova_vaga->vaga_anterior = aux_vaga;
                nova_vaga->proxima_vaga = aux_vaga->proxima_vaga;
                aux_vaga->proxima_vaga = nova_vaga;
                nova_vaga->comprimento = espaco_sobrando;
                nova_vaga->ocupada = false;
                nova_vaga->placa = 0;
            }
            aux_vaga->comprimento = comprimento_estacionar;
            aux_vaga->placa = placa;
            return 10;
        }
    }
    return 0;
}

void desocupaVaga(Estacionamento *estacionamento, int placa){
    Vaga *aux_vaga;
    aux_vaga = estacionamento->inicio;
    while(aux_vaga){
        if(aux_vaga->placa == placa){
            int espaco_sobrando = aux_vaga->comprimento;
            
            if(aux_vaga->proxima_vaga){
                if(!aux_vaga->proxima_vaga->ocupada){
                    aux_vaga->proxima_vaga->comprimento += espaco_sobrando;
                    aux_vaga->proxima_vaga->vaga_anterior = aux_vaga->vaga_anterior;
                    aux_vaga->vaga_anterior->proxima_vaga = aux_vaga->proxima_vaga;
                    free(aux_vaga);
                } else {
                    if(aux_vaga->vaga_anterior){
                        if(!aux_vaga->vaga_anterior->ocupada){
                            aux_vaga->vaga_anterior->comprimento += espaco_sobrando;
                            aux_vaga->vaga_anterior->proxima_vaga = aux_vaga->proxima_vaga;
                            aux_vaga->proxima_vaga->vaga_anterior = aux_vaga->vaga_anterior;
                            free(aux_vaga);
                        } else {
                            aux_vaga->ocupada = false;
                            aux_vaga->placa = 0;
                        }
                    }
                }
            } else {
                
                if(aux_vaga->vaga_anterior){
                    
                    if(!aux_vaga->vaga_anterior->ocupada){
                        aux_vaga->vaga_anterior->comprimento += espaco_sobrando;
                        aux_vaga->vaga_anterior->proxima_vaga = aux_vaga->proxima_vaga;
                        if(aux_vaga->proxima_vaga) aux_vaga->proxima_vaga->vaga_anterior = aux_vaga->vaga_anterior;
                        free(aux_vaga);
                    } else {
                        aux_vaga->ocupada = false;
                        aux_vaga->placa = 0;
                    }
                }
                
            }
            return;
        }
        aux_vaga = aux_vaga->proxima_vaga;
    }
}

void freeEstacionamento(Estacionamento *estacionamento){
    Vaga *aux_vaga;
    aux_vaga = estacionamento->inicio;
    while(aux_vaga->proxima_vaga){
        aux_vaga = aux_vaga->proxima_vaga;
    }
    aux_vaga = aux_vaga->vaga_anterior;
    while(aux_vaga){
        free(aux_vaga->proxima_vaga);
        aux_vaga = aux_vaga->vaga_anterior;
    }
}

int main(){
    Estacionamento estacionamento;
    int total_eventos, faturamento = 0;
    while(scanf("%d %d\n", &estacionamento.comprimento, &total_eventos) != EOF){
        faturamento = 0;
        alocaEstacionamento(&estacionamento);
        char acao; int placa, comprimento_veiculo;
        for(int evento = 0; evento < total_eventos; evento++){
            scanf("%c %d", &acao, &placa);
            if(acao == 'C'){
                scanf("%d\n", &comprimento_veiculo);
                faturamento += ocupaNovaVaga(&estacionamento, comprimento_veiculo, placa);
            } else if (acao == 'S'){
                scanf("\n");
                desocupaVaga(&estacionamento, placa);
            }
        }
        freeEstacionamento(&estacionamento);
        printf("%d\n", faturamento);
    }
    return 0;
}