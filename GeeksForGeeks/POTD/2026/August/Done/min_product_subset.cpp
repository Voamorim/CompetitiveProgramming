#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minProd(vector<int>& arr) {
        const int n = arr.size();
        
        int neg = 0;

        for(int i = 0; i < n; ++i){
            if(arr[i] < 0) neg += 1;
        }

        if(!neg){
            return *min_element(arr.begin(), arr.end());
        }

        int ans = 1;
        if(neg & 1){
            for(auto &x : arr){
                if(x == 0) continue;
                ans *= x;
            }
            return ans;
        }

        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; ++i){
            if(neg == 1 && arr[i] < 0) continue;
            if(arr[i] == 0) continue;

            ans *= arr[i];
            neg -= 1;
        }

        return ans;
    }
};

int main(){
    vector<int> arr = {1, 2, 3};
    cout << Solution().minProd(arr) << endl;
    vector<int> arr2 = {4, -2, 5};
    cout << Solution().minProd(arr2) << endl;
    return 0;
}
