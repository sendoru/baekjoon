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

    int n;
    cin >> n;
    vector<ll> v = {0};
    for(int i = 1; i <= n; i++) {
        ll cur;
        cin >> cur;
        v.push_back(v.back() + cur);
    }

    vector<int> dp(n + 1, MOD1);
    // dp[i] : i번쨰 힌지까지 접었을 때 위쪽으로 튀어나온 최소 길이
    // dp 배열을 다 구했으면 답은 min(max(dp[i], v.back() - v[i])) for i in (0 .. n)
    // dp[i] = min(x[i] - x[j]) for j < i with 제약조건 (x[j] + dp[j] <= x[i])
    dp[0] = 0;
    

    return 0;
}