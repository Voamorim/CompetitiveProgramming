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
vector<ll> steps(1000010, LLONG_MAX);

// Functions
void solve(int n){
    steps[0] = 0;


    for(int i = 1; i <= n; i++){
        for(int k = i; k > 0; k/=10){
            int val = k%10;

            if(i - val >= 0 and steps[i-val] != LLONG_MAX){
                steps[i] = min(steps[i], steps[i-val] + 1);
            }
        }

    }
}


int main(){ _
    int n; cin >> n;

    solve(n);

    cout << steps[n] << endl;


	return 0;
}
