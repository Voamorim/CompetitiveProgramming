#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        int t; cin >> t;

        mp[s] = t;
    } 

    long long ans = 0;

    string s; 
    while(cin >> s){
        if(s == ".") break;
        ans += mp[s]; 
    }

    cout << ans << endl;

    return 0;
}
