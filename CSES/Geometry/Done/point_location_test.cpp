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

#define int long long

signed main(){ _
    int t; cin >> t;

    while(t--){
        int x1, x2, x3;
        int y1, y2, y3;

        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        pii v1, v2;

        v1 = {x2 - x1, y2 - y1};
        v2 = {x3 - x1, y3 - y1};

        int cross = (v1.F * v2.S) - (v1.S * v2.F);

        if(cross == 0) cout << "TOUCH" << endl;
        else if (cross < 0) cout << "RIGHT" << endl;
        else cout << "LEFT" << endl;
    }

	return 0;
}
