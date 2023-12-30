//
// Created by sendo on 2023-01-27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> dr = {0, 1, -1, 0, 0}, dc = {0, 0, 0, 1, -1};

ll dist(pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // dp[i][j] := i번째 노드의 j번째 방향까지 오는 데 걸리는 최단거리
    ll n;
    cin >> n;
    pll orig;
    cin >> orig.first >> orig.second;
    vector<pll> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
        i.first -= orig.first;
        i.second -= orig.second;
    }

    vector<vector<ll>> dp(n, vector<ll>(5, 1e18));
    for(int i = 0; i < 5; i++)
        dp[0][i] = (abs(v[0].first + dr[i]) + abs(v[0].second + dc[i]));

    // i: 현재 처리하는 노드 번호
    for(int i = 1; i < n; i++) {
        // j: 현재 처리하는 노드의 방향
        for(int j = 0; j < 5; j++){
            ll currR = v[i].first + dr[j], currC = v[i].second + dc[j];
            // k: 직전 노드의 방향
            for(int k = 0; k < 5; k++)
            {
                ll prevR = v[i - 1].first + dr[k], prevC = v[i - 1].second + dc[k];
                ll dist = abs(currR - prevR) + abs(currC - prevC);
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + dist);
            }
        }
    }


    cout << *min_element(dp.back().begin(), dp.back().end());
    return 0;
}