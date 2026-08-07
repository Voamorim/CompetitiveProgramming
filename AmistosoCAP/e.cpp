#include <bits/stdc++.h>

using namespace std;

vector<int> primos(110);

bool primo(int x, int i){
    if(x <= 1) return false;
    for(int j = 0; j < i; ++j){
        if(primos[j] * primos[j] > x) return true;
        if(x % primos[j] == 0) return false;
    }
    return true;
}

void calculaPprimos(int p = 100){
    primos[0] = 2; 

    int i = 1;

    int val = 3;
    while(i < 100){
        if(primo(val, i)){
            primos[i++] = val;
        }
        val += 2;
    }
}

bool divisivel(int x, int p){
    if(p == 0) return false;

    for(int i = 0; i < p; i ++){
        if(x % primos[i] == 0) return true;
    }
    return false;
}

int main(){
    long long i, f, p; cin >> i >> f >> p;
    
    if(p > 0) calculaPprimos(p);

    long long sum = (f * (f + 1) / 2) - ((i-1) * i / 2);

    for(long long j = i; j <= f; ++j){
        if(divisivel(j, p)) sum -= j;
    }
    cout << sum << endl;

    return 0;
}
