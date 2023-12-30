//
// Created by sendo on 2023-01-28.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class Trie {
    vector<vector<int>> _next;
    vector<int> _terminal, _cnt;

public:
    void push(string& s) {
        int node = 0;
        for (int i = 0; i < s.length(); i++) {
            while (node >= _next.size()) {
                _next.push_back(vector<int>(26));
                _terminal.push_back(0);
                _cnt.push_back(0);
            }
            if (_next[node][s[i] - 'a'] == 0) {
                _next[node][s[i] - 'a'] = _next.size();
                _next.push_back(vector<int>(26));
                _cnt.push_back(0);
                _terminal.push_back(0);
            }
            _cnt[node]++;
            node = _next[node][s[i] - 'a'];
        }
        _cnt[node]++;
        _terminal[node] = 1;
    }

    int solve(string& s) {
        int node = 0, ans = 0;
        for(;ans < s.length(); ans++) {
            node = _next[node][s[ans] - 'a'];
            if (node == 0 || _cnt[node] <= 1) {
                break;
            }
        }
        return ans;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;


    return 0;
}