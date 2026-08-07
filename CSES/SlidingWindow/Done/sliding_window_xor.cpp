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

#define MAXN 10000010

int n, k;
int x, a, b, c;

vector<ll> v(MAXN);

vector<int> prefix(MAXN);
vector<int> sufix(MAXN);

ll ans;

signed main(){ _
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    v[0] = x;
    for(int i = 1; i < n; ++i){
        v[i] = (v[i-1] * a + b) % c;
    }

    // Constrói o prefixo 
    prefix[0] = v[0];
    for(int i = 1; i < n; ++i){
        if(i % k == 0) 
            prefix[i] = v[i];
        else
            prefix[i] = prefix[i-1] ^ v[i];
    }

    // Constrói o sufixo
    sufix[n-1] = v[n-1];
    for(int i = n - 2; i >= 0; --i){
        if(i % k == k - 1)
            sufix[i] = v[i];
        else 
            sufix[i] = sufix[i+1] ^ v[i];
    }

    for(int i = k - 1; i < n; ++i){
        if(i % k == k - 1)
            ans ^= prefix[i];
        else
            ans ^= (prefix[i] ^ sufix[i-(k-1)]);
    }

    cout << ans << endl;

	return 0;
}
