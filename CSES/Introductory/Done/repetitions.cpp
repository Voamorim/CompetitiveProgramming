#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second
typedef long long ll;

int main(){
    string dna; cin >> dna;
    int maior_repeticao = 0, atual = 1; int len_string = size(dna);
    for(int c = 1; c < len_string; c++){
        if(dna[c] == dna[c-1]){
            atual++;
        } else {
            if(atual > maior_repeticao) maior_repeticao = atual;
            atual = 1;
        }
    }
    if(atual > maior_repeticao) maior_repeticao = atual;
    cout << maior_repeticao << endl;
    return 0;
}