#include <bits/stdc++.h>
 
/*ACEITO*/

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> fatorial(11);
    fatorial[0] = 1;
    for(int i = 1; i < 11; i++) fatorial[i] = fatorial[i-1]*i;
    
    int qnt_fatoriais = 0;
    int qnt_div;
    //Para obter o minimo eh preciso obter o maior fatorial que cabe em N
    for(int i = 10; i > 0; i--){
        qnt_div = N/fatorial[i]; //quantas vezes o fatorial cabe em N
        qnt_fatoriais += qnt_div; 
        N -= qnt_div * fatorial[i];
    }
    cout << qnt_fatoriais << endl;
    return 0;
}