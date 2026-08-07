/*ACEITO*/

#include <stdio.h>

/*
 -> Assume-se que nunca ocorre um empate
 -> Os carros são enumerados de 1 a N
 -> Os mais bem colocados são os que terminaram a corrida no menor tempo
 */

typedef struct tabela{
    int tempo;
    int pos;
} Tabela;

int main(){
    int num_carros = 0, num_voltas = 0, tempo_atual = 0;
    scanf("%d %d", &num_carros, &num_voltas);
    Tabela tabela[num_carros];
    for(int i = 0; i < num_carros; i++){
        tabela[i].tempo = 0;
    }
    for(int i = 0; i < num_carros; i++){
        for(int j = 0; j < num_voltas; j++){
            scanf("%d", &tempo_atual);
            tabela[i].tempo += tempo_atual;
        }
        tabela[i].pos = i+1;
    }
    
    Tabela aux;
    for(int i = 0; i < num_carros; i++){
        for(int j = 0; j < num_carros; j++){
            if (tabela[i].tempo > tabela[j].tempo){
                aux.tempo = tabela[i].tempo;
                aux.pos = tabela[i].pos;
                tabela[i].tempo = tabela[j].tempo;
                tabela[i].pos = tabela[j].pos;
                tabela[j].tempo = aux.tempo;
                tabela[j].pos = aux.pos;
            }
        }
    }
    for(int i = num_carros - 1; i > num_carros - 4; i--){
        printf("%d\n", tabela[i].pos);
    }
    return 0;
}