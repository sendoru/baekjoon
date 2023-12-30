#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string wc = "atcoder";

    string s, t;
    cin >> s >> t;

    map<char, int> sMap, tMap;
    for(auto c : s)
        sMap[c]++;
    for(auto c : t)
        tMap[c]++;

    bool ans = true;
    int sLack = 0, tLack = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        if (sMap[c] != tMap[c] && find(wc.begin(), wc.end(), c) == wc.end()) {
            cout << "No";
            return 0;
        }
        else {
            if (sMap[c] - tMap[c] > 0) {
                tLack += sMap[c] - tMap[c];
            }
            else {
                sLack += tMap[c] - sMap[c];
            }
        }
    }

    if (sMap['@'] >= sLack && tMap['@'] >= tLack) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}