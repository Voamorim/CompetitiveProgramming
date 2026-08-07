#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define _ iostream::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define pb push_back

typedef long long ll;

struct No{
    int chave;
    No *e, *d;
};

No* insere(No *raiz, int chave){
    if(not raiz){
        No* novo_no = new No;

        novo_no->chave = chave;
        novo_no->e = NULL;
        novo_no->d = NULL;
        return novo_no;
    }
    if(chave > raiz->chave){
        raiz->d = insere(raiz->d, chave);
    } else {
        raiz->e = insere(raiz->e, chave);
    }
    return raiz;
}

void imprimePreOrdem(No* raiz){
    if(not raiz) return;
    cout << ' ' << raiz->chave;
    imprimePreOrdem(raiz->e);
    imprimePreOrdem(raiz->d);
}

void imprimeEmOrdem(No* raiz){
    if(not raiz) return;
    imprimeEmOrdem(raiz->e);
    cout << ' ' << raiz->chave;
    imprimeEmOrdem(raiz->d);
}

void imprimePosOrdem(No* raiz){
    if(not raiz) return;
    imprimePosOrdem(raiz->e);
    imprimePosOrdem(raiz->d);
    cout << ' ' << raiz->chave;
}

void impressao(No *raiz){
    cout << "Pre.:";
        imprimePreOrdem(raiz);
        cout << endl;
        cout << "In..:";
        imprimeEmOrdem(raiz);
        cout << endl;
        cout << "Post:";
        imprimePosOrdem(raiz);
        cout << endl;
        cout << endl;
}

int main(){ _
    int c; cin >> c;
    for(int caso = 1; caso <= c; caso++){
        int n; cin >> n;
        cout << "Case " << caso << ":" << endl;
        No* raiz = NULL;

        for(int i = 0; i < n; i++){
            int num; cin >> num;
            raiz = insere(raiz, num);
        }

        impressao(raiz);
    }

    return 0;
}
