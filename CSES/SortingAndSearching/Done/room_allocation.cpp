#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'

// Defines
#define MAXN 200010


// Variables
int n;
int k;
map<int, int> users;
vector<pair<int, pair<int, int>>> sl;
stack<int> rooms;
bool nfirst;
priority_queue<pair<int, int>> ans;

// Functions
void print(int r){
	if(nfirst){
		cout << ' ' << r;
	} else {
		cout << r;
		nfirst = true;
	}
}


// triple: <entry, <cost, customer >>
int main(){ _
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int a, b; cin >> a >> b; b++;
		
		// Customer's arrival
		sl.PB(make_pair(a, make_pair(1, i)));
		// Customer's departure
		sl.PB(make_pair(b, make_pair(-1, i)));
	}

	// Sorts the sweep line
	sort(sl.begin(), sl.end());
	

	int maxk = 0;
	
	// Computes the minimum number of rooms required
	// In other words, the maximum number of customers in the hotel at the same time
	for(auto line : sl){
		k += line.S.F;			
		maxk = k > maxk ? k : maxk;
	}

	k = maxk;
	cout << k << endl;
	
	// Inserts all the required rooms on the stack
	for(int i = k; i >= 1; i--){
		rooms.push(i);
	}
	
	

	for(auto line : sl){
		// If the current customer is leaving
		if(line.S.F == -1){
			int r;
			r = users[line.S.S]; // recovers the number of the room used by the leaving customer
			users.erase(line.S.S); // removes the customer from the map
			rooms.push(r); // re-adds the used room to the stack
		}
		// If the current customer is arriving to the hotel       
		else {
			int x = rooms.top(); rooms.pop(); // picks one of the rooms available
			users[line.S.S] = x; 
			ans.push(make_pair(-line.S.S,x));
		}
	}

	while(!ans.empty()){
		auto x = ans.top(); ans.pop();
		print(x.S);
	}

	cout << endl;
	return 0;
}
