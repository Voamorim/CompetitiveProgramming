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

#define MAXN 501

int n, m;
vector<vector<int>> matrix(MAXN, vector<int> (MAXN));

bool check(int i, int j){
    if(i - 1 >= 0 and matrix[i][j] == matrix[i-1][j]) return false;
    if(j - 1 >= 0 and matrix[i][j] == matrix[i][j-1]) return false;

    return true;
}

signed main(){ _
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c; cin >> c;
            matrix[i][j] = (c - 'A' + 1) % 4;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int k = 0;  
            do{
                if(check(i, j)) break; 
                matrix[i][j] = (matrix[i][j] + 1) % 4;

                k++;
            } while(k < 3);

            if(k == 3){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        } 
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++ j){
            char c = (char) matrix[i][j] + 'A';
            cout << c;
        }
        cout << endl;
    }

	return 0;
}
