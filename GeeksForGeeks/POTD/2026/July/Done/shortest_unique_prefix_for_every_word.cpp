#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> findPrefixes(vector<string>& arr) {
        const int MAXNODES = 1000001;
        const int MAXCHAR = 26;

        unordered_map<int, unordered_map<int, int>> trie;
        unordered_map<int, unordered_map<int, int>> words;

        int nnodes = 1;
        for (auto& w : arr) {
            int curr_node = 1;
            for (int i = 0; i < w.size(); ++i) {
                unsigned char c = w[i];

                if (not trie[curr_node][(int)c - 'a']) {
                    trie[curr_node][(int)c - 'a'] = ++nnodes;
                }

                words[curr_node][(int)c - 'a'] += 1;

                curr_node = trie[curr_node][(int)c - 'a'];
            }
        }

        vector<string> ans;

        for (auto& w : arr) {
            int curr_node = 1;

            string prefix = "";

            for (int i = 0; i < w.size(); ++i) {
                unsigned char c = w[i];

                prefix.push_back(c);

                if (words[curr_node][(int)c - 'a'] == 1 or i == w.size() - 1) {
                    break;
                }

                curr_node = trie[curr_node][(int)c - 'a'];
            }

            ans.push_back(prefix);
        }

        return ans;
    }
};

int main() {
    vector<string> arr = {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
    vector<string> ans = Solution().findPrefixes(arr);
    for (auto& s : ans) cout << s << endl;

    return 0;
}
