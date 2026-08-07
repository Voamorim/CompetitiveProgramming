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

int n;

bool ask(int m){
    cout << "? " << m << endl;
    fflush(stdin);
    string ans; cin >> ans;
    fflush(stdin);
    if(ans == "R") return true;
    return false;
}

int main(){
    cin >> n;

    int low = 1, high = n;

    bool clow = ask(low), chigh = ask(high);

    if(clow == chigh){
        cout << "! " << low << endl;
        return 0;
    }

    int i = 18;
    while(i--){
        int mid = (low + high) / 2;

        bool cmid = ask(mid);

        // Caso low-mid é ímpar e as extremidades diferentes
        if((mid - low + 1 & 1) and (cmid != clow)){
            chigh = cmid;
            high = mid;
        } else if (not(mid - low + 1 & 1) and (cmid == clow)){
            chigh = cmid;
            high = mid;
        } else if ((high - mid + 1 & 1) and (cmid != chigh)){
            clow = cmid;
            low = mid;
        } else {
            clow = cmid;
            low = mid;
        }
    }
    cout << "! " << low << endl;
    fflush(stdin);
	return 0;
}
