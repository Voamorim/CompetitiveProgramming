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

int n;

signed main(){ _
    cin >> n;

    ll area = 0; 
    vec p[n];
    cin >> p[0].x >> p[0].y;

    for(int i = 1; i < n; ++i){
        cin >> p[i].x >> p[i].y;

        area += cross(p[i-1], p[i]);
    }
    area += cross(p[n-1], p[0]);

    cout << abs(area) << endl;
	return 0;
}
