#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

ll modPow(ll b, ll e) {
    if (e == 0) return 1;
    ll h = modPow(b, e / 2);
    if (e & 1) return ((h * h) % MOD1 * b % MOD1) % MOD1;
    return (h * h) % MOD1;
}

ll modInv(ll b) {
    return modPow(b, MOD1 - 2);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    ll v0 = modPow(n, 3 * m), s0 = (6 * modPow(n, 2 * m)) % MOD1;
    ll ev = (12 * n - 16) * modInv(modPow(n, 3)) % MOD1;
    ll s = 6 * modPow(4, m) % MOD1
            * ((n - 2) % MOD1 * modPow((3*n-4) % MOD1, m) % MOD1
            + (n - 1) * modPow(n - 1, m) % MOD1 + MOD1) % MOD1;
    s *= modInv((2 * n - 3) % MOD1);
    s %= MOD1;

    cout << v0 * modPow(ev, m) % MOD1 << ' ' << s;
    return 0;
}