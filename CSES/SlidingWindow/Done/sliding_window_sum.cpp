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
vector<ll> prefix_sum(MAXN); 
vector<ll> arr(MAXN);

ll ans = 0;

int main(){ _
    cin >> n >> k; 
    cin >> x >> a >> b >> c;

    arr[0] = x;
    for(int i = 1; i <= n; ++i){
        arr[i] = (arr[i-1] * a + b) % c;
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];

        if(i - k >= 0){
            ans ^= prefix_sum[i] - prefix_sum[i-k];
        }
    }

    cout << ans << endl;

	return 0;
}
