#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> freq(26);

int main() {
    cin >> s;
    int n = s.size();

    for (auto& c : s) {
        freq[c - 'A'] += 1;

        int maxl = n & 1 ? n / 2 + 1 : n / 2;
        if (freq[c - 'A'] > maxl) {
            cout << -1 << endl;
            return 0;
        }
    }

    set<pair<int, int>> sorted_freqs;

    for (int i = 0; i < 26; ++i) {
        if (not freq[i]) continue;

        sorted_freqs.insert({-freq[i], -i});
    }

    string ans = "";
    int remaining = n;
    while (remaining) {
        for (int i = 0; i < 26; ++i) {
            if (not freq[i]) continue;
            if (ans.size() and ans[ans.size() - 1] == i + 'A') continue;

            auto it = sorted_freqs.begin();
            auto [max_freq, c] = *it;

            if (-c == i) {
                ans.push_back(i + 'A');
                freq[i] -= 1;
                sorted_freqs.erase(it);
                sorted_freqs.insert({-freq[i], -i});

                remaining -= 1;
                break;
            }

            int maxl = remaining & 1 ? remaining / 2 + 1 : remaining / 2;
            if (-max_freq > remaining / 2) {
                if (i > -c) {
                    cout << -1 << endl;
                    return 0;
                }
                continue;
            }

            ans.push_back(i + 'A');
            remaining -= 1;

            sorted_freqs.erase({-freq[i], -i});
            freq[i] -= 1;
            sorted_freqs.insert({-freq[i], -i});

            break;
        }
    }

    if (ans.size() != n)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
