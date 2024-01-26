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

    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    vector<bool> done_on_s(n), done_on_t(n);
    int g = 0;
    vector<vector<int>> idxs(10);

    for(int i = 0; i < n; i++) {
        idxs[s[i] - '0'].push_back(i);
    }

    for(int num = 9; num >= 0; num--) {
        while(!idxs[num].empty()) {
            int idx = idxs[num].back();
            idxs[num].pop_back();
            if (done_on_t[idx]) {
                continue;
            }
            done_on_t[idx] = true;

            if (!done_on_s[idx]) {
                if (s2[idx] != s2[n - 1 - idx]) {
                    s2[n - 1 - idx] = num + '0';
                }
                else {
                    while (!done_on_s[g]) {
                        g++;
                    }
                    s2[g] = s2[n - 1 - g] = num + '0';
                    done_on_t[n - 1 - idx] = true;
                }
            }

            else {
                
            }
        }
    }

    return 0;
}