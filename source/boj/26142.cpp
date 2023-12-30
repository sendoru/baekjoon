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
    vector<pll> d(n);
    for(int i = 0; i < n; i++)
        cin >> d[i].first >> d[i].second;

    sort(d.begin(), d.end());
    vector<ll> ans(n);
    for(int i = 0; i < n; i++)
        ans[n - 1] += d[i].first * i + d[i].second;

    for(int i = n - 2; i >= 0; i--) {
        vector<ll> pSum(d.size() + 1);
        for(int j = d.size() - 1; j >= 0; j--)
            pSum[j] = pSum[j + 1] + d[j].first;

        ll opt = 0, idx = -1;
        // exclude d[j]
        for(int j = 0; j < d.size(); j++) {
            ll cur = ans[i + 1] - (d[j].second + j * d[j].first + pSum[j + 1]);
            if (cur > opt) {
                opt = cur;
                idx = j;
            }
        }

        d.erase(d.begin() + idx);
        ans[i] = opt;
    }

    for(auto i : ans)
        cout << i << '\n';
    return 0;
}