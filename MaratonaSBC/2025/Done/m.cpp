#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n, k;
vector<int> walls (MAXN);

bool possible(long long height){
    int add = -1;
    for(int i = n - 1; i >= 0; i--){
        if(add > 0) add -= 1;

        if(walls[i] < height){
            if(add == -1){ 
                add = k; 
            } 

            if(add == 0) return false;

            if(walls[i] + add >= height){
                continue;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        cin >> walls[i];
    }

    long long low = 1, high = 2000000000;

    while(low < high){
        long long mid = (low + high) / 2;

        if(possible(mid)){
            low = mid;
        } else {
            high = mid - 1;
        }

        if(high - low == 1){
            if(possible(high)) low = high;

            break;
        }
    }
    
    cout << low << endl;

    return 0;
}
