#include<bits/stdc++.h>

using namespace std;

vector<string> palavra = {"UAI", "TREM", "SO"};
int idx = 0;
long long val = 10;

int main(){
    int n; cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    if(n == 2){
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    cout << 1 << ' ' << 1;

    long long i = 1, j = 1;

    n -= 2;
    while(n--){
        long long k = i + j;
        j = i;
        i = k;

        if(to_string(i).size() > to_string(j).size()){
            i = val;
            val *= 10;
            cout << ' ' << palavra[idx];
            idx = (idx + 1) % 3;
        } else {
            cout << ' ' << i;
        }

    }   
    cout << endl;
    return 0;
}
