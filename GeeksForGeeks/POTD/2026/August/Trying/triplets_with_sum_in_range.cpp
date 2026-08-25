#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
    int countTriplets(vector<int> &arr, int l, int r) {
        const int n = arr.size();
        sort(arr.begin(), arr.end()); 
        int ans = 0;

        for(int i = 0; i < n - 2; ++i){
            if(arr[i] > r) continue;

            int low = i + 1, high = n - 1; 
            
            while(low < high){
                int sum = arr[i] + arr[low] + arr[high];     

                if(sum <= r){
                    ans += high - low;
                    low += 1;
                } else {
                    high -= 1;
                }
            }

            low = i + 1, high = n - 1;

            while(low < high){
                int sum = arr[i] + arr[low] + arr[high];

                if(sum < l){
                    ans -= high - low;
                    low += 1;
                } else high -= 1;
            }

        }

        return ans;
    }
};

int main(){
    int l, r;
    vector<int> arr = {8, 3, 5, 2};
    l = 7, r = 11; 
    cout << Solution().countTriplets(arr, l, r) << endl;
    vector<int> arr2 = {5, 1, 4, 3, 2};
    l = 2, r = 7; 
    cout << Solution().countTriplets(arr2, l, r) << endl;

    return 0;
}
