#include <bits/stdc++.h>
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

pll extgcd(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    ll x, y;
    tie(y, x) = extgcd(b, a % b);
    y -= a / b * x;
    return make_pair(x, y);
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x, y;
    cin >> x >> y;

    ll _gcd = gcd(x, y);

    if (_gcd > 2) {
        cout << -1;
    }

    else if (_gcd == 2) {
        auto sol = extgcd(y, -x);
        cout << sol.first << ' ' << sol.second;
    }

    else if (_gcd == 1) {
        auto sol = extgcd(y, -x);
        cout << sol.first * 2ll << ' ' << sol.second * 2ll;
    }

    return 0;
}