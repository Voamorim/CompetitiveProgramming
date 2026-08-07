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
#define all(vet) (vet).begin, (vet).end()
#define MOD 1000000007


// Defines


// Variables

vector<vector<int>> g(10, vector<int> (10));
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};


// Functions

bool check(int x, int y){
    if(x < 0 or x >= 8 or y < 0 or y >= 8 or g[y][x] == 1) return false;
    return true;
}

bool finalpoint(piii w){
    if(g[w.S.F][w.F] == 2) return true;
    return false;
}

ll bfs(piii src) {
    queue<piii> q;
    if(finalpoint(src)) return 0;
    q.push(src);
    g[src.S.F][src.F] = 1;
    while(not q.empty()){
        piii w = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){

            if(not check(dx[i] + w.F, dy[i] + w.S.F)){
                continue;
            }
            piii nw = {w.F + dx[i], {w.S.F + dy[i], w.S.S + 1}};
            q.push(nw);

            if(finalpoint(nw)) return nw.S.S;
            g[nw.S.F][nw.F] = 1;

        }

    }
    return 12345;
}


int main(){ _


    string a, b;

    while(cin >> a >> b){
        int xa = a[0] - 'a';
        int ya = fabs(a[1] - '1' - 7);
        int xb = b[0] - 'a';
        int yb = fabs(b[1] - '1' - 7);

        for(int i = 0; i < 8; i++){
            g[i].assign(8, 0);
        }



        g[yb][xb] = 2;
        ll ans = bfs({xa, {ya, 0}});

        cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves." << endl;

        g[yb][xb] = 0;
    }
	return 0;
}
