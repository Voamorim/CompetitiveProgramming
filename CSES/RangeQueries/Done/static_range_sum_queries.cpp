#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define endl '\n'

// Defines


// Variables
vector<ll> v;
vector<ll> bitv;

// Functions

ll sum(int idx){
    ll soma = 0;
    while(idx > 0){
        soma += bitv[idx];
        int bitmsig = (idx & (-idx));
        idx -= bitmsig;
    }
    return soma;
}

// Atualiza a BIT modificando o valor de somente um elemento
void update(int idx, ll x){
    while(idx < bitv.size()){
        bitv[idx] += x;
        int bitmsig = (idx & (-idx));
        idx += bitmsig;
    }
}

// Retorna o elemento na posição idx
ll pointQuery(int idx){
    return sum(idx);
}

// Retorna a soma de todos os elementos no intervalo [l, r]
ll rangeQuery(int l, int r){
    return sum(r) - sum(l - 1);
}

// Adiciona x a todos os elementos no intervalo [l, r]
void rangeUpdate(int l, int r, ll x){
    update(l, x);
    update(r+1, -x);
}

int main(){ _
    int n, q; cin >> n >> q;
    v.resize(n+1);
    bitv.resize(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        update(i, v[i]);
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << rangeQuery(a, b) << endl;
    }

    return 0;
}
