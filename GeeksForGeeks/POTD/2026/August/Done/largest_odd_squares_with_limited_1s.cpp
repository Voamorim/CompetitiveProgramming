#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool possible(int n, int m, int li, int ui, int lj, int uj){
        if(li == 0 or lj == 0 or ui > n or uj > m) return false;
        return true;
    }

    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
        int n = mat.size();
        int m = mat[0].size();
    
        vector<vector<int>> ps (n + 1, vector<int> (m + 1, 0));

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + mat[i-1][j-1];
            }
        }

        vector<int> ans;

        for(int q = 0; q < queries.size(); ++q){
            int i = queries[q][0], j = queries[q][1];
            i += 1, j += 1;

            int best = 0;
            int curr = ps[i][j] - ps[i-1][j] - ps[i][j-1] + ps[i-1][j-1];

            if(curr > k){
                ans.push_back(-1);
                continue;
            }
            best = curr;

            int li = i-1, ui = i+1;
            int lj = j-1, uj = j+1;
            int fac = 3;
            int best_fac = 1;

            while(possible(n, m, li, ui, lj, uj)){
                int curr = ps[ui][uj] - ps[li-1][uj] - ps[ui][lj-1] + ps[li-1][lj-1];

                if(curr > k){
                    break;
                }
                best = curr;
                best_fac = fac;

                li -= 1, lj -=1, ui += 1, uj += 1;
                fac += 2; 
            }
            ans.push_back(best_fac);
        }

        return ans;
    }
};

int main(){

    return 0;
}

