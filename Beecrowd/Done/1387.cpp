#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

/*
    -> Og conta os filhos com a mão direita e as filhas com a mão esquerda
*/

int main(){
    int L = 1, R = 1;
    while(1){
        cin >> L >> R;
        if(!L && !R) return 0;
        cout << L+R << endl;
    }
    return 0;
}