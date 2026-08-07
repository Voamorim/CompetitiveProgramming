/*ACEITO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int a;
    struct No *e, *d;
} No;

No* insere(No *raiz, int a){
    if(!raiz){
        No* novo_no = (No*)malloc(sizeof(No));
        novo_no->e = NULL; novo_no->d = NULL; novo_no->a = a;
        return novo_no;
    } else {
        if(a > raiz->a) raiz->d = insere(raiz->d, a);
        else raiz->e = insere(raiz->e, a);
    }
    return raiz;
}

void menorAlturaNivel(No *raiz, int nivel, int resultado[]){
    if(!raiz) return;

    if(raiz->a < resultado[nivel] || resultado[nivel] == -1) resultado[nivel] = raiz->a;

    menorAlturaNivel(raiz->e, nivel+1, resultado);
    menorAlturaNivel(raiz->d, nivel+1, resultado);
}

int main(){
    int n; scanf("%d", &n);

    int resultado[251];
    memset(resultado, -1, sizeof(resultado));

    No *raiz = NULL;

    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        raiz = insere(raiz, a);
    }

    menorAlturaNivel(raiz, 0, resultado);
    for(int i = 0; i < n; i++){
        if(resultado[i] >= 0) printf("%d %d\n", i, resultado[i]);
        else break;
    }
    return 0;
}