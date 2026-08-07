#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

int main(){
    int n; int num;
    cin >> n;
    vector<int> pares, impares;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num & 1){
            impares.push_back(num);
        } else {
            pares.push_back(num);
        }
    }
    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end());

    for(int i = 0; i < pares.size(); i++){
        cout << pares[i] << endl;
    }
    for(int i = impares.size()-1; i >= 0; i--){
        cout << impares[i] << endl;
    }
    return 0;
}