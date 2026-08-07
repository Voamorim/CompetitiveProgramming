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

struct point{
    ll x, y;
    point() {}
    point(ll _x, ll _y) : x(_x), y(_y) {}

    bool operator == (point other) const {
        return x == other.x and y == other.y;
    }
};

bool operator < (point a, point b) {
    return a.y < b.y or (a.y == b.y and a.x < b.x);
}

bool insegment (point p1, point p2, point p3){
    return (min(p1.x, p2.x) <= p3.x and p3.x <= max(p1.x, p2.x)) and
           (min(p1.y, p2.y) <= p3.y and p3.y <= max(p1.y, p2.y)); 
}

struct vec {
    ll x, y;   

    vec() {}
    vec(ll _x, ll _y) : x(_x), y(_y) {  } 
    vec(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
};

ll dot(vec u, vec v){
    return u.x * v.x + u.y * v.y;
}

ll cross(vec u, vec v) {
    return u.x * v.y - u.y * v.x;
}

ll ccw(point p1, point p2, point p3){
    ll res = cross(vec(p1, p2), vec(p1, p3));

    if(res > 0) return 1;
    else if (res < 0) return 2;
    return 0;
}

int t;

signed main(){ _
    cin >> t;

    while(t--){
        point p[4];
        for(int i = 0; i < 4; ++i) cin >> p[i].x >> p[i].y;

        int o1 = ccw(p[0], p[1], p[2]);
        int o2 = ccw(p[0], p[1], p[3]);
        int o3 = ccw(p[2], p[3], p[0]);
        int o4 = ccw(p[2], p[3], p[1]);

        bool ans = false;

        if(o1 != o2 and o3 != o4) ans = true;

        if(not o1 and insegment(p[0], p[1], p[2])) ans = true;
        if(not o2 and insegment(p[0], p[1], p[3])) ans = true;
        if(not o3 and insegment(p[2], p[3], p[0])) ans = true;
        if(not o4 and insegment(p[2], p[3], p[1])) ans = true;

        cout << (ans ? "YES" : "NO") << endl;
    }

	return 0;
}
