//
// Created by sendo on 2023-01-29.
//
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
    cout.precision(12);

    int n, k;
    cin >> n >> k;

    vector<pll> v(n);
    for (auto& i : v)
        cin >> i.first >> i.second;

    double ans = 0;
    double l = 0., r = 1.;
    for(int _ = 0; _ < 30; _++) {
        double m = (l + r) / 2;
        sort(v.begin(), v.end(), [&] (pll a, pll b) -> bool
            {return a.second * m - a.first < b.second * m - b.first;});
        ll cur_p = 0, cur_q = 0;
        for(int i = 0; i < k; i++) {
            cur_p += v[i].first;
            cur_q += v[i].second;
        }
        double cur = (double)cur_p / cur_q;
        if (cur >= m) {
            ans = max(ans, cur);
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << ans;
    return 0;
}