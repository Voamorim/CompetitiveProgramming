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

int ask(int i, char p){
    cout << p << " " << i << endl;
    fflush(stdin);
    int ans; cin >> ans;
    fflush(stdin);
    return ans;
}

int main(){
    int n, k; cin >> n >> k;

    int i = 25;
    int low = max(1, k - n), high = min(k, n);

    int l1 = INT_MAX, l2 = INT_MAX;
    int r1 = INT_MIN, r2 = INT_MIN;
    while(i--){
        int mid = (low + high) / 2;

        int isweeden = k - mid;

        l1 = INT_MAX, l2 = INT_MAX;
        r1 = INT_MIN, r2 = INT_MIN;

        if(mid <= n and mid >= 1) l1 = ask(mid, 'F');
        if(isweeden <= n and isweeden >= 1) l2 = ask(isweeden, 'S');
        if(mid + 1 <= n) r1 = ask(mid + 1, 'F');
        if(isweeden + 1 <= n) r2 = ask(isweeden + 1, 'S');

        if((l1 >= r2 and l2 >= r1) or i == 1){
            int ans = mid + isweeden == k ? min(l1, l2) : max(l1, l2);

            cout << "! " << ans << endl;
            return 0;
        } else if (l1 < r2){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

	return 0;
}
