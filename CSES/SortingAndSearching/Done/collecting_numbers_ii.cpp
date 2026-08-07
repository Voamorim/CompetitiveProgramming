#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

int n, m;

signed main(){ _
    cin >> n >> m;

    vector<int> values(n + 1);
    vector<int> pos(n + 1);

    for(int i = 0; i < n; ++i){
        int x; cin >> x;

        values[i] = x;
        pos[x] = i;
    }

    ll ans = n;
   
    // Calcula a resposta antes das queries
    set<int> s;
    for(int i = 0; i < n; ++i){
        // Caso o próximo elemento ainda não tenha aparecido, a quantidade de
        // passadas pode ser reduzida em 1
        if(s.find(values[i] + 1) == s.end() and values[i] != n){
            ans -= 1;
        }
        s.insert(values[i]);
    }

    // Calcula a resposta depois de cada uma das mudanças
    int l, r; 
    set<pii> updates; 
    while(m--){
        cin >> l >> r;
        l--, r--;

        if(values[l] + 1 <= n)
            updates.insert(make_pair(values[l], values[l] + 1));
        if(values[l] - 1 >= 1)
            updates.insert(make_pair(values[l] - 1, values[l]));
        if(values[r] + 1 <= n)
            updates.insert(make_pair(values[r], values[r] + 1));
        if(values[r] - 1 >= 1)
            updates.insert(make_pair(values[r] - 1, values[r]));

        // Caso exista uma inversão antes da troca, precisamos desconsiderá-la
        // da resposta para depois avaliar novamente
        for(auto p : updates){
            ans -= (pos[p.F] > pos[p.S]);
        }

        // Realiza a troca de posição
        swap(values[l], values[r]);
        pos[values[l]] = l;
        pos[values[r]] = r;

        // Incrementa a resposta novamente de acordo com as inversões causadas
        for(auto p : updates){
            ans += (pos[p.F] > pos[p.S]);
        }

        cout << ans << endl;
        updates.clear();
    }
	return 0;
}
