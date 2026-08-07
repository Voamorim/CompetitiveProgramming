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


// Functions



int main(){ _
    int n; cin >> n;
    while(n--){
        int p, c, f; cin >> p >> c >> f;
        vector<ll> pesos(p);
        ll maior = -INT_MAX;
        ll total = 0;
        for(int i = 0; i < p; i++){
            cin >> pesos[i];
            maior = max(maior, pesos[i]);
            total += pesos[i];
        }

        ll l = maior, r = total;
        ll mid = 0;
        while(l < r){

            ll c_necessarios = 1;
            ll qnt = 0;

            mid = (l+r)/2;
            for(int i = 0; i < p; i++){
                if(qnt + pesos[i] <= mid){
                    qnt += pesos[i];
                } else {
                    c_necessarios++;
                    qnt = pesos[i];
                }

            }
            if(c_necessarios > c) l = mid+1;
            else r = mid;


        }

        cout << r << " $" << r * f * c << endl;
    }
	return 0;
}
