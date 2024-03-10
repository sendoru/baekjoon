#include <bits/stdc++.h>

#include "atcoder/all"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int ccw(pll a, pll b, pll c)
{
    ll ret = a.first * b.second + b.first * c.second + c.first * a.second;
    ret -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if (ret > 0) {
        return 1;
    }
    else if (ret < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pll> dots(n);
    for (int i = 0; i < n; i++) {
        cin >> dots[i].first >> dots[i].second;
    }

    int ans = 0;
    vector<vector<int>> triplets;
    for (int t = 0; t < 100; t++) {
        // randomize the order of the dots
        int cur_ans = 0;
        vector<bool> used(n, false);
        random_shuffle(dots.begin(), dots.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (!(used[i] || used[j] || used[k]) &&
                        ccw(dots[i], dots[j], dots[k]) != 0) {
                        used[i] = used[j] = used[k] = true;
                        cur_ans += 1;
                    }
                }
            }
        }

        ans = max(ans, cur_ans);
    }

    cout << ans << '\n';
}
