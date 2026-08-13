#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size(); 

        vector<vector<int>> dp(n, vector<int> (n, 0));       

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dp[i][j] = mat[i][j];

                if(i <= 0) continue;

                int best = 0;
                for(int k = 0; k < n; ++k){
                    if(k == j) continue;

                    best = max(best, dp[i-1][k]);
                }

                dp[i][j] += best; 
            }
        }

        return *max_element(dp[n-1].begin(), dp[n-1].end()); 
    }
};

int main(){
    vector<vector<int>> matrix = {{3, 1, 2}, {4, 8, 5}, {6, 9, 7}};
    cout << Solution().zigzagSequence(matrix) << endl;
    

    return 0;
}

