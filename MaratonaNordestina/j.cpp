#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010

int n, q;
vector<int> values (MAXN);
vector<pair<int, int>> segtree(4*MAXN, {INT_MIN, -1});

pair<int, int> merge(int lc, int rc){
	pair<int, int> ans;
	if(segtree[lc].first > segtree[rc].first){
		ans.first = segtree[lc].first;
		ans.second = segtree[lc].second;	
	} else {
		ans.first = segtree[rc].first;
		ans.second = segtree[rc].second;
	}

	return ans;
}

void segtreeBuild(int tl = 0, int tr = n-1, int node = 1){
	if(tl == tr){
		segtree[node].first = values[tl];
		segtree[node].second = tl;
		return;
	}

	int tmid = (tl + tr) / 2;

	int lc = node * 2, rc = lc + 1;

	segtreeBuild(tl, tmid, node  * 2);
	segtreeBuild(tmid + 1, tr, node * 2 + 1);

	segtree[node] = merge(lc, rc);
}

pair<int, int> segtreeQuery(int l, int r, int tl = 0, int tr = n - 1, int node = 1){
	if(tl > r or tr < l) return {INT_MIN, -1};

	if(tl >= l and tr <= r){
		return segtree[node];
	}

	int tmid = (tl + tr) / 2;
	auto [x, i] = segtreeQuery(l, r, tl, tmid, node * 2);
	auto [y, k] = segtreeQuery(l, r, tmid + 1, tr, node*2+1);
	
	if(x > y){
		return make_pair(x, i);
	} else {
		return make_pair(y, k);
	}
}

int main(){
	cin >> n >> q;
	for(int i = 0; i < n; ++i) cin >> values[i];
	segtreeBuild();

	while(q--){
		int l, r; cin >> l >> r;
		l-=1, r-=1;
		auto [maxval, j] = segtreeQuery(l, r);


		if(j == l or j == r){
			cout << "Adilson" << endl;
			continue;
		}

		int lrange = j - l + 1;
		int rrange = r - j + 1;

		if((lrange & 1) == (rrange & 1)){
			cout << "Reginaldo" << endl;
		} else {
			cout << "Adilson" << endl;
		}
	}
	return 0;
}
