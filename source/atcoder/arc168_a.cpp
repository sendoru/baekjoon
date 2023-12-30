#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

ll modPow(ll b, ll e, ll mod) {
    if (e == 0) return 1ll;
    ll half = modPow(b, e / 2, mod);
    if (e % 2 == 0) return half * half % mod;
    return (half * half % mod) * b % mod;
}

ll modInv(ll b, ll mod) {
    return modPow(b, mod - 2, mod);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> cnt(3);
    for(auto i : s) {
        cnt[i - 'A']++;
    }

    // a랑 b랑 쳐바꾸기 p번
    // b랑 c랑 쳐바꾸기 q번
    // c랑 a랑 쳐바꾸기 r번
    // sum of (n(a) C p * n(b) C p * n(b) C q * n(c) C q * n(c) C r * n(a) C r)
    // where p, q, r in Z+ and p + q + r <= k

    // 3중루프 : k^3

    // nCk
    vector<vector<ll>> combs(n + 1, vector<ll>(k + 1, 1));

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            ll temp = modInv(j, MOD9);
            combs[i][j] = combs[i][j - 1] * (i - j + 1) % MOD9 * modInv(j, MOD9) % MOD9;
        }
    }
    ll ans = 0;
    for(int p = 0; p <= k; p++) {
        for(int q = 0; q <= k; q++) {
            for(int r = 0; r <= k; r++) {
                if (p + q + r <= k
                    && p <= cnt[0] && p <= cnt[1]
                    && q <= cnt[1] && q <= cnt[2]
                    && r <= cnt[0] && r <= cnt[2]
                    && cnt[1] - p >= 0 && cnt[2] - q >= 0 && cnt[0] - p >= 0) {

                    ll cur = combs[cnt[0]][p] * combs[cnt[1]][p] % MOD9
                            * combs[cnt[1] ][q] % MOD9 * combs[cnt[2]][q] % MOD9
                            * combs[cnt[2] ][r] % MOD9 * combs[cnt[0]][r] % MOD9;

                    ans += cur;
                    ans %= MOD9;
                }
            }
        }
    }

    cout << ans;
    return 0;
}

// 2 3 4
// 2 3 0
// 2 2 0
// 2 1 0
//

// ABC -> CBA ->