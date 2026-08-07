#include <bits/stdc++.h>

using namespace std;

int ask(int x, char c){
    cout << c << " " << x << endl;
    cout.flush();
    int ans; cin >> ans; 
    return ans;
} 

int askL(int x){ return ask(x, 'L'); }
int askC(int x){ return ask(x, 'C'); }

int main(){
    int n; cin >> n;

    int linha1 = askL(1);

    // Devemos fazer com que a quantidade de estados diferentes das lâmpadas
    // da primeira linha seja igual a 0
    int dif = min(linha1, n - linha1);
    int j = 1;

    // Enquanto a linha não for toda acesa ou toda apagada... 
    while(dif){
        askC(j); // Testa inverter o estado da coluna j

        linha1 = askL(1); // Vê o resultado da inversão
        int new_dif = min(linha1, n - linha1);

        // Caso a diferença tenha aumentado, é preciso desfazer a inversão
        if(new_dif > dif) askC(j);
        else dif = new_dif;
       
        // Passa para a próxima lâmpada
        j++;
    }

    // Quando a primeira linha está toda acesa ou toda apagada, temos a garantia
    // de que as demais linhas também estão com as lâmpadas todas acesas ou 
    // todas apagadas
    for(int i = 1; i <= n; ++i){
        int l = askL(i);
        if(not l) askL(i);
    }

    cout << "FIM" << endl;
    cout.flush();

    return 0;
}
