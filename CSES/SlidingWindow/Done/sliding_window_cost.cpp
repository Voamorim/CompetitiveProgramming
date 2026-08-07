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

int n, k;

vector<int> values;

multiset<int> low_half;
ll low_half_sum;

multiset<int> upper_half;
ll upper_half_sum;

void insertNew(int x){
    if(low_half.size() == 0){
        low_half.insert(x);
        low_half_sum += x;

        return;
    } else if (upper_half.size() == 0){
        if(x < *low_half.begin()){
            auto it = low_half.begin();
            upper_half.insert(*it);
            upper_half_sum += *it;
            
            low_half_sum -= *it;
            low_half.erase(it);

            low_half.insert(x);
            low_half_sum += x;
        } else {
            upper_half.insert(x);
            upper_half_sum += x;
        }
        return;
    }

    if(x > *low_half.rbegin()){
        upper_half.insert(x);
        upper_half_sum += x;
    } else {
        low_half.insert(x);
        low_half_sum += x;
    }

    if(upper_half.size() > low_half.size()){
        int val = *upper_half.begin();
        upper_half.erase(upper_half.begin()); 
        low_half.insert(val);

        upper_half_sum -= val;
        low_half_sum += val;
    } else if (low_half.size() - upper_half.size() > 1){
        int val = *low_half.rbegin();
        low_half.erase(low_half.find(val));
        upper_half.insert(val);
        
        upper_half_sum += val;
        low_half_sum -= val;
    }
}

void eraseLast(int i){
    int x = values[i];

    auto pos = low_half.find(x);
    if(pos != low_half.end()){
        low_half_sum -= *pos;
        low_half.erase(pos);

        if(upper_half.size() > low_half.size()){ 
            int val = *upper_half.begin();
            upper_half.erase(upper_half.begin()); 
            low_half.insert(val);

            upper_half_sum -= val;
            low_half_sum += val;
        }

        return;
    }
   
    pos = upper_half.find(x);
    upper_half_sum -= *pos;
    upper_half.erase(pos);

    if (low_half.size() - upper_half.size() > 1){
        int val = *low_half.rbegin();
        low_half.erase(low_half.find(val));
        upper_half.insert(val);
        upper_half_sum += val;
        low_half_sum -= val;
    } 
}

signed main(){ _
    cin >> n >> k;

    values.resize(n);

    for(int i = 0; i < k; ++i){
        int x; cin >> x;
       
        values[i] = x;

        insertNew(x);
    }

    ll balance_cost = upper_half_sum - low_half_sum;

    balance_cost = low_half.size() != upper_half.size() ?
                   balance_cost + *low_half.rbegin() : balance_cost;

    cout << balance_cost;

    for(int i = k; i < n; ++i){
        eraseLast(i - k);

        int x; cin >> x;
        values[i] = x;

        insertNew(x);

        balance_cost = upper_half_sum - low_half_sum;

        balance_cost = low_half.size() != upper_half.size() ?
                       balance_cost + *low_half.rbegin() : balance_cost;

        cout << ' ' << balance_cost;
    }

    cout << endl;    

	return 0;
}
