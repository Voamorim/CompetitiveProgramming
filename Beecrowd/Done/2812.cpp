#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl

int main() {
    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        vector<int> v; v.resize(0);
        for(int i = 0; i < m; i++){
            int num; cin >> num;
            
            if(num % 2 == 1){ 
                v.push_back(num);   
            }
        }
        sort(v.begin(), v.end());
        int tam = ceil(v.size()/2);
        for(int i = 0, j = v.size() - 1; i < tam, j >= tam; i++, j--){
            if(i == 0 && j != i) cout << v[j] << " " << v[i];
            else if (i == j and i == 0) cout << v[i];

            else if(j == i) cout << " " << v[i];
            else cout << " " <<  v[j] << " " << v[i];
        }

        cout << endl;
    }
    return 0;
}