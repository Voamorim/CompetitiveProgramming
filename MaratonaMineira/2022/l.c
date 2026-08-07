#include <string.h>
#include <stdio.h>

typedef struct criancas{
    char nome[9];
    int idade;
    int dormiu;
} Criancas;

int main(){
    char caractere;
    int N; //Numero de crianças
    scanf("%d\n", &N);
    Criancas criancas[N];

    int i = 0, j = 0, ii = 0;
    char linha[N*10];
    scanf("%[^\n]\n", linha);
    int tam_linha = strlen(linha);
    for(; i < tam_linha; i++){
        if(linha[i] != ' '){
            criancas[j].nome[ii] = linha[i];
            ii += 1;
        } else {
            criancas[j].nome[ii] = '\0';
            criancas[j].dormiu = 0;
            ii = 0;
            j += 1;
        }
    }
    
    char nome[9];
    i = 0, j = 0, ii = 0;
    for(int i = 0; i < N; i++){
        scanf("%s\n", nome);
        for(int k = 0; k < N; k ++){
            if(!strcmp(criancas[k].nome, nome)){
                criancas[k].idade = i;
            }
        }
    }

    int menor_idade = 0;

    for(int quartos = 0; quartos < N; quartos ++){
        for(int varrer = quartos; varrer < N; varrer++){
            if(criancas[varrer].idade <= menor_idade && criancas[varrer].dormiu == 0){
                printf("%s ", criancas[varrer].nome);
            }
            
        }
        criancas[quartos].dormiu = 1;
        if(criancas[quartos].idade <= menor_idade){
            menor_idade = N;
            for(int l = quartos+1; l < N; l++){
                if(criancas[l].idade < menor_idade) menor_idade = criancas[l].idade;
            }
        }
    }

    printf("\n");
    return 0;
}