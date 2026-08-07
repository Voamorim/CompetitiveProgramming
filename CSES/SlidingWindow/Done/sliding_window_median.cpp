#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>

// Defines



// Variables



// Functions



int main(){ _
	int k, n; cin >> n >> k;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.PB(x);
	}

	ordered_set<ii> oset;
	for(int i = 0; i < k; i++){
		oset.insert({v[i], i});
	}
	int med = k/2;
	if(!(k & 1)){
		med -= 1;
	}
	cout << (*(oset.find_by_order(med))).F;

	for(int i = 1; i + k <= n; i++){
		auto it = oset.find({v[i-1], i-1});
		// if(*it == v[i-1]) cout << "ok" << endl;
		oset.erase(it);
		oset.insert({v[i+k-1], i+k-1});

		cout << ' ' << (*oset.find_by_order(med)).F;
	}

	cout << endl;
	return 0;
}
