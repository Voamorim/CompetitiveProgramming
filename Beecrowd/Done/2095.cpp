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
multiset<int> ngo;
vector<int> qua;

// Functions



int main(){ _
    int s; cin >> s;
    for(int i = 0; i < s; i++){
        int x; cin >> x;
        qua.PB(x);
    }

    for(int i = 0; i < s; i++){
        int x; cin >> x;
        ngo.insert(x);
    }

    sort(qua.begin(), qua.end());

    ll ans = 0;
    for(auto x : qua){
        auto p = ngo.upper_bound(x);
        if(p != ngo.end()){
            ans++;

            ngo.erase(p);
        } else {
            continue;
        }

    }

    cout << ans << endl;
	return 0;
}
