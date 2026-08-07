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


long double epss = 0.000000001;


// Variables
vector<int> v;

// Functions
int check(long double h, int a){
    long double tot = 0;
    for(auto x : v){
        if(x - h > 0){
            tot += x - h;
        }
    }

    if(fabs(tot - a) < epss) return 0;
    if(tot - a > epss){ return 1;}
    return -1;

}


int main(){ _
    int a;
    int n;
    while(1){
    cin >> n >> a;
    if(not n and not a) return 0;
    int maior = -INT_MAX;
    int sum = 0;
    v.clear();
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        maior = max(maior, x);
        sum += x;
        v.PB(x);
    }

    double eps = 0.000000000000001;

    if(sum == a){
        cout << ":D" << endl;
    } else{
    int it = 0;
    long double l = 0, h = maior;long double mid = 0;
    while(fabs(h - l) >= eps){
        mid = (l + h)/2;
        it++;
        int  k = check(mid, a);
        if(k == 0){
            break;
        } else if (k == -1){
            h = mid;
        } else {
            l = mid;
        }
    }

    int r = check(mid, a);


    if(r == 0){
        cout << fixed <<  setprecision(4) << mid << endl;

    } else{
        cout << "-.-" << endl;
    }

    }
    }
	return 0;
}
