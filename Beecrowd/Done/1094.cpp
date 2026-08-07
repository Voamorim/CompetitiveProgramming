#include <bits/stdc++.h>

/*ACEITO*/


using namespace std;

/*
    3 tipos de cobaias:
        1. Sapos (S)
        2. Ratos (R)
        3. Coelhos (C)

*/

int total_cobaias, total_coelhos, total_ratos, total_sapos;
double porcentual;

int main(){
    int n;
    cin >> n;
    vector<int> cobaias(n);
    char tipo_cobaia;
    for(int i = 0; i < n; i++){
        scanf("%d %c\n", &cobaias[i], &tipo_cobaia);
        total_cobaias += cobaias[i];
        switch (tipo_cobaia){
            case 'C':
                total_coelhos += cobaias[i];
                break;
            case 'R':
                total_ratos += cobaias[i];
                break;
            case 'S':
                total_sapos += cobaias[i];
                break;
        }
    }

    cout << "Total: " << total_cobaias << " cobaias" << endl;
    cout << "Total de coelhos: " << total_coelhos << endl;
    cout << "Total de ratos: " << total_ratos << endl;
    cout << "Total de sapos: " << total_sapos << endl;
    porcentual = (double) total_coelhos / total_cobaias * 100;
    cout << "Percentual de coelhos: " << fixed << setprecision(2) << porcentual << " %" << endl;
    porcentual = (double) total_ratos / total_cobaias * 100;
    cout << "Percentual de ratos: " << fixed << setprecision(2) << porcentual << " %" << endl;
    porcentual = (double) total_sapos / total_cobaias * 100;
    cout << "Percentual de sapos: " << fixed << setprecision(2) << porcentual << " %" << endl;
    return 0;
}