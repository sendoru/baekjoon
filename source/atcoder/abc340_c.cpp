#include <bits/stdc++.h>
// #include "atcoder/all"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

map<ll, ll> m;

ll solve(ll n) {
    if (m.find(n) != m.end()) return m[n];
    if (n < 2) return 0;
    if (n % 2 == 0) {
        ll half = solve(n / 2);
        return m[n] = 2 * half + n;
    }
    return m[n] = solve(n / 2) + solve(n / 2 + 1) + n;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;

    // 8 -> 4 * 2-> 2 * 4 -> 1 * 8
    // 8 + 8 + 8
    // n == 2^k 형태면 k lg(k)

    cout << solve(n);

    return 0;
}