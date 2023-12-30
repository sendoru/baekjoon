//
// Created by sendo on 2023-09-02.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

ll solve(vector<vector<pair<vector<int>, ll>>>& cases, int r, int g, int b) {
    ll ret = 0;
    ll curR = 0, curG = 0, curB = 0, curCnt = 1;
    function<void(int)> f = [&] (int curIdx) -> void {
        if (curIdx == cases.size()) {
            if (curR <= r && curG <= g && curB <= b) {
                ret += curCnt;
            }
            return;
        }
        for (int i = 0; i < cases[curIdx].size(); i++) {
            curR += cases[curIdx][i].first[0];
            curG += cases[curIdx][i].first[1];
            curB += cases[curIdx][i].first[2];
            curCnt *= cases[curIdx][i].second;
            f(curIdx + 1);
            curR -= cases[curIdx][i].first[0];
            curG -= cases[curIdx][i].first[1];
            curB -= cases[curIdx][i].first[2];
            curCnt /= cases[curIdx][i].second;
        }
    };

    f(1);
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<ll>> comb(15, vector<ll>(15, 1));
    for(int i = 2; i < 15; i++) {
        comb[i][1] = i;
        for(int j = 2; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    // n C n/2
    // n C n/3 * (2/3)n C n/3

    int n, r, g, b;
    cin >> n >> r >> g >> b;

    vector<vector<pair<vector<int>, ll>>> cases(n + 1);
    for(int i = 1; i <= n; i++) {
        cases[i].push_back({{i, 0, 0}, 1});
        cases[i].push_back({{0, i, 0}, 1});
        cases[i].push_back({{0, 0, i}, 1});
        if (i % 2 == 0) {
            cases[i].push_back({{i/2, i/2, 0}, comb[i][i/2]});
            cases[i].push_back({{0, i/2, i/2}, comb[i][i/2]});
            cases[i].push_back({{i/2, 0, i/2}, comb[i][i/2]});
        }
        if (i % 3 == 0) {
            cases[i].push_back({{i/3, i/3, i/3}, comb[i][i/3] * comb[2*i/3][i/3]});
        }
    }

    cout << solve(cases, r, g ,b);

    return 0;
}