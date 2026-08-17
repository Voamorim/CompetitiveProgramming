#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        const int n = arr.size();

        vector<long long> paper (n + 1, 0); 
        paper[0] = s;
        long long sum = s;

        for(int i = 1; i <= n; ++i){
            paper[i] = sum + arr[i-1];
            sum += paper[i];
        }

        bool ans = false;

        // we have a superincreasing sequence
        // 
        // so the sum of all the values before paper[i]
        // can't be >= the value of paper[i]
        //
        // this means that we can solve the subset sum 
        // problem without the need of dp
        //
        // we need to traverse the array backwards and, 
        // every time x >= paper[i], we need to decrement
        // x by paper[i], because it wont be possible to 
        // make the sum x without the element paper[i]

        for(int i = n; i >= 0; --i){
            if(x < paper[i]) continue;
            x -= paper[i]; 
        }

        ans = x == 0;
        return ans; 
    }
};


int main(){
    int s, x;
    vector<int> arr = {1, 2, 4, 2};
    s = 1, x = 7; 
    cout << Solution().isPossible(arr, s, x) << endl; 

    vector<int> arr1 = {51, 88};
    s = 100, x = 500;
    cout << Solution().isPossible(arr1, s, x) << endl;

    return 0;
}
