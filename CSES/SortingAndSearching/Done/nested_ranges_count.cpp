#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>

int n;
vector<piii> rangess;

vector<int> contains;
vector<int> contained;

signed main(){ _
    cin >> n;

    contains.resize(n);
    contained.resize(n);

    for(int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;

        rangess.PB(make_pair(x, make_pair(-y, i)));
    } 

    sort(rangess.begin(), rangess.end());

    ordered_set os;

    for(int i = 0; i < n; ++i){
        int idx = rangess[i].S.S;
        pii range = {-rangess[i].S.F, -i};

        os.insert(range);
    
        contained[idx] = os.size() - os.order_of_key(range) - 1; 
    }

    os.clear();

    for(int i = n - 1; i >= 0; --i){
        int idx = rangess[i].S.S;
        pii range = {-rangess[i].S.F, -i};

        os.insert(range);
    
        contains[idx] = os.order_of_key(range);  
    }

    for(auto &x : contains){
        cout << x << ' ';
    }
    cout << endl;

    for(auto &x : contained){
        cout << x << ' ';
    }
    cout << endl;

	return 0;
}
