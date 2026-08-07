/*ACEITO*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *e, *d;
} No;

No* insere(No *raiz, int chave){
    if(!raiz){
        No* novo_no = (No*)malloc(sizeof(No));

        novo_no->chave = chave;
        novo_no->e = NULL;
        novo_no->d = NULL;
        return novo_no;
    }

    if(chave > raiz->chave){
        raiz->d = insere(raiz->d, chave);
    } else if (chave < raiz->chave){
        raiz->e = insere(raiz->e, chave);
    }
    return raiz;
}

void imprimePreOrdem(No* raiz){
    if(!raiz) return;
    printf(" %d", raiz->chave);
    imprimePreOrdem(raiz->e);
    imprimePreOrdem(raiz->d);
}

void imprimeEmOrdem(No* raiz){
    if(!raiz) return;
    imprimeEmOrdem(raiz->e);
    printf(" %d", raiz->chave);
    imprimeEmOrdem(raiz->d);    
}

void imprimePosOrdem(No* raiz){
    if(!raiz) return;

    imprimePosOrdem(raiz->e);
    imprimePosOrdem(raiz->d);
    printf(" %d", raiz->chave);
}

void impressao(No* raiz){
    printf("Pre.:"); imprimePreOrdem(raiz); printf("\n");
    printf("In.:"); imprimeEmOrdem(raiz); printf("\n");
    printf("Post.:"); imprimePosOrdem(raiz); printf("\n\n");
}

int main(){
    int c; scanf("%d", &c);
    for(int caso = 1; caso <= c; caso++){
        printf("Case %d:\n", caso);
        int n; scanf("%d", &n);
        No* raiz = NULL;

        for(int i = 0; i < n; i++){
            int num; scanf("%d", &num);
            raiz = insere(raiz, num);
        }
        impressao(raiz);
    }
    return 0;
}