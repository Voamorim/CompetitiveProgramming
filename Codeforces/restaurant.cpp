#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.s < b.s;
}

int main(){
    int n; cin >> n;

    vector<pair<int, int>> reservas;
    for(int i = 0; i < n; i ++){
        int a, b; cin >> a >> b;
        reservas.push_back({a, b});
    }

    sort(reservas.begin(), reservas.end(), cmp);

    int total_reservas = 0;
    int fim = -1;
    for(int i = 0; i < n; i++){
        if(reservas[i].f > fim){
            fim = reservas[i].s;
            total_reservas++;
        }
    }
    cout << total_reservas << endl;
    return 0;
}