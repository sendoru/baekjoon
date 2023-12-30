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
const int BUCKET_SIZE = 222;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    map<int, vector<int>> p;
    for(int i = 0; i < n; i++) {
        int x ,y;
        cin >> x >> y;
        if (p[x].empty()) {
            p[x] = {y};
        }
        else {
            p[x].push_back(y);
        }
    }

    vector<pair<int, vector<int>>> large, small;
    for(auto& [x, y] : p) {
        if (y.size() > BUCKET_SIZE) {
            large.push_back({x, y});
            sort(large.back().second.begin(), large.back().second.end());
        }
        else {
            small.push_back({x, y});
            sort(small.back().second.begin(), small.back().second.end());
        }
    }

    ll ans = 0;

    // large - large
    for(auto& [x1, y1s] : large) {
        for(auto& [x2, y2s] : large) {
            if (x1 == x2 || y2s.size() > y1s.size() || (y2s.size() == y1s.size() && x2 > x1)) {
                continue;
            }
            ll k = 0;
            for (auto y2 : y2s) {
                auto iter = lower_bound(y1s.begin(), y1s.end(), y2);
                if (iter != y1s.end() && *iter == y2) {
                    k++;
                }
            }
            ans += k * (k - 1) / 2;
        }
    }

    // large - small
    for(auto& [x1, y1s] : large) {
        for(auto& [x2, y2s] : small) {
            ll k = 0;
            for (auto y2 : y2s) {
                auto iter = lower_bound(y1s.begin(), y1s.end(), y2);
                if (iter != y1s.end() && *iter == y2) {
                    k++;
                }
            }
            ans += k * (k - 1) / 2;
        }
    }

    // small - small
    vector<pii> small_pair;
    for(auto& [x, y] : small) {
        for(int i = 0; i < y.size(); i++) {
            for(int j = i + 1; j < y.size(); j++) {
                small_pair.push_back({y[i], y[j]});
            }
        }
    }

    map<pii, ll> m;
    for(auto& i : small_pair) {
        m[i]++;
    }

    for(auto& [k, v] : m) {
        ans += v * (v - 1) / 2;
    }

    cout << ans;

    return 0;
}