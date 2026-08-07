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

#define MAXN 200010

int n, k;
vector<int> v(MAXN);
multiset<int> kelements; 
multiset<int> window;

signed main(){ _
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i) cin >> v[i];

    for(int i = 0; i <= k; ++i) {
        //cout << "inserido: " << i << endl << endl;
        kelements.insert(i);
    }

    for(int i = 0; i < k; ++i){
        auto it = kelements.find(v[i]);
        window.insert(v[i]);

        if(it != kelements.end()){
            //cout << "removido: " << *it << endl << endl;
            kelements.erase(it);
        }
    }

    cout << *kelements.lower_bound(0);

    for(int i = k; i < n; ++i){
        auto it = kelements.find(v[i]);
        if(it != kelements.end()){ 
            //cout << "removido: " << *it << endl << endl;
            kelements.erase(it);
        }
        window.insert(v[i]);

        window.erase(window.find(v[i-k]));
        if(window.find(v[i-k]) == window.end()){
            //cout << "inserido: " << v[i-k] << endl << endl;
            kelements.insert(v[i-k]);
        }

        cout << ' ' << *kelements.lower_bound(0);
    }

    cout << endl;

	return 0;
}
