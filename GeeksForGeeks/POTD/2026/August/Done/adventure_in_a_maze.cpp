#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1000000000 + 7;

        vector<vector<int>> paths (n, vector<int> (n, 0));
        vector<vector<int>> adventure (n, vector<int> (n, 0));

        paths[0][0] = 1;
        adventure[0][0] = grid[0][0];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i - 1 >= 0 && grid[i-1][j] >= 2 && paths[i-1][j]){
                    paths[i][j] = (paths[i-1][j] + paths[i][j]) % MOD;
                    
                    adventure[i][j] = max(adventure[i][j], 
                                          adventure[i-1][j] + grid[i][j]);
                }

                if(j - 1 >= 0 && (grid[i][j-1] == 1 or grid[i][j-1] == 3) && paths[i][j-1]){
                    paths[i][j] = (paths[i][j-1] + paths[i][j]) % MOD;
                    adventure[i][j] = max(adventure[i][j],
                                          adventure[i][j-1] + grid[i][j]);
                }
            }
        }

        vector<int> ans (2, 0);
        ans[0] = paths[n-1][n-1];
        ans[1] = adventure[n-1][n-1];
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{3, 2}, {1, 3}}; 
    cout << Solution().findWays(grid)[0] << endl;
    cout << Solution().findWays(grid)[1] << endl;
    
    vector<vector<int>> grid2 = {{1, 1, 3, 2, 1}, {3, 2, 2, 1, 2}, {1, 3, 3, 1, 3}, {1, 2, 3, 1, 2}, {1, 1, 1, 3, 1}}; 
    cout << Solution().findWays(grid2)[0] << endl;
    cout << Solution().findWays(grid2)[1] << endl;

    return 0;
}
