#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define MAXN 200010

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k;

int main() {
    _ cin >> n >> k;

    vector<pair<int, int>> w(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        w[i] = make_pair(x, i);
    }

    sort(w.begin(), w.end());

    vector<int> v(n);
    int val = 0;
    v[0] = val;
    for (int i = 1; i < n; ++i) {
        int curr = w[i].first, prev = w[i - 1].first;

        if (curr != prev) val++;

        v[w[i].second] = val;
    }

    ordered_set<pair<int, int>> os;

    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        int value = v[i];

        pair<int, int> node = make_pair(value, i);

        os.insert(node);
        int idx = os.order_of_key(node);

        ans += os.size() - (idx + 1);
    }
    cout << ans;

    for (int i = k; i < n; ++i) {
        int value = v[i];
        pair<int, int> node = make_pair(value, i);
        pair<int, int> rem = make_pair(v[i - k], i - k);

        int dec = os.order_of_key(rem);
        ans -= dec;
        os.erase(rem);

        os.insert(node);
        int idx = os.order_of_key(node);

        ans += os.size() - (idx + 1);
        cout << ' ' << ans;
    }
    cout << endl;

    return 0;
}
