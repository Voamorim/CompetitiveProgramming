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

// Defines



// Variables



// Functions



int main(){ _
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> dependencies(n+1, 0); // quantidade de "pais" de cada vértice
    vector<int> ans;


    while(m--){
        int a, b; cin >> a >> b;

        adj[a].PB(b);
        dependencies[b]++;
    }

    queue<int> q;

    // adiciona os cursos que não tem dependência nenhuma entre os possíveis a serem feitos
    for(int i = 1; i < n+1; i++){
        if(not dependencies[i]){
            q.push(i);
        }
    }


    while(not q.empty()){
        int course = q.front();
        q.pop();
        ans.PB(course);

        // decrementa a quantidade de dependências de todos os cursos dependentes de um curso possível
        for(auto son : adj[course]){
            dependencies[son]--;
            if(not dependencies[son]){
                q.push(son);
            }
        }
    }

    // se a quantidade de cursos possíveis não for a mesma que a quantidade de cursos, então não é possível realizar todos os cursos
    if(n != ans.size()){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << endl;
    }

	return 0;
}
