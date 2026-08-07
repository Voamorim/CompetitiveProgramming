#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> v (n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v[i] = a;
    }

    int maior_soma = INT_MIN;
    int seq_atual = 0;


    for(int i = 0; i < n; i++){
        if(v[i] + seq_atual >= 0){
            seq_atual += v[i];
            if(seq_atual > maior_soma) maior_soma = seq_atual; 
        } else {
            if(v[i] > maior_soma) maior_soma = v[i];
            seq_atual = 0;
        }
    }

    cout << maior_soma << endl;
    return 0;
}