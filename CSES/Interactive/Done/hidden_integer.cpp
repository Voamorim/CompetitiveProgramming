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

#define MAXN 1000000000

int main(){
    int x = MAXN;

    int low = 1;

    int i = 30;
    while(i--){
        string ans;

        int mid = (low + x)/2;
        cout << "? " << mid << endl;
        fflush(stdin);

        cin >> ans;
        fflush(stdin);

        if(ans == "YES"){
            low = mid + 1;
        } else {
            x = mid;
        }
    }

    cout << "! " << x << endl;
    fflush(stdin);
	return 0;
}
