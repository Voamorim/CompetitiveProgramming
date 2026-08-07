#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define pii pair<int, int>

using namespace std;

#define MAX_CHAR 256

int bmh(string text, string pattern){
    if(pattern.size() > text.size()) return 0; 

    vector<int> T(256, pattern.size()); 

    for(int i = 0; i < pattern.size() - 1; ++i){
        T[pattern[i]] = pattern.size() - 1 - i;
    }

    int matches = 0;

    for(int i = 0; i <= text.size() - pattern.size();){
        int p = pattern.size() - 1;

        while(p >= 0 and pattern[p] == text[i + p]){
            p -= 1;
        }

        matches += (p < 0);

        i += T[text[i + pattern.size() - 1]];
    }

    return matches;
}

int main(){ _
    int t; cin >> t;

    while(t--){
        int l, c; cin >> l >> c;
        cin.ignore();

        vector<string> caca_palavras_horizontal(l);
        vector<string> caca_palavras_vertical(c);
        for(int i = 0; i < l; ++i){
            for(int j = 0; j < c; ++j){
                char chr; cin >> chr;

                caca_palavras_horizontal[i].PB(chr);
                caca_palavras_vertical[j].PB(chr);
            }
        }

        int p; cin >> p;
        vector<string> palavras(p);
        for(string & palavra : palavras) cin >> palavra;


        for(int k = 0; k < p; ++k){
            int ans = 0;
            for(int i = 0; i < l; ++i){
                ans += bmh(caca_palavras_horizontal[i], palavras[k]);
            }

            if(palavras[k].size() > 1){
                for(int i = 0; i < c; ++i){
                    ans += bmh(caca_palavras_vertical[i], palavras[k]);
                }
            }
            cout << ans << endl;
        }       
    }
    return 0;
} 
