#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;

vector<vector<ll>> combDP;
vector<ll> ans;


ll comb(ll n, ll r)
{
    ll& ret = combDP[n][r];
    if (ret != -1)
        return ret;
    if (r == 0 || n == r)
        return ret = 1;
    return ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % MOD;
}

ll modPow(ll b, ll e)
{
    if (e == 0) return 1;
    if (e & 1) return modPow(b, e - 1) * b % MOD;
    ll half = modPow(b, e / 2);
    return half * half % MOD;
}

ll modInv(ll n) { return modPow(n, MOD - 2); }

ll solve(ll n, ll k)
{
    ll& ret = ans[k];
    if (ret != -1)
        return ret;
    if (k == 0)
        return ret = n;
    if (k == 1)
        return ret = (n * (n + 1)) % MOD * modInv(2) % MOD;

    k++;
    ret = (modPow(n + 1, k) - 1 + MOD) % MOD;
    for(ll i = 0; i <= k - 2; i++)
    {
        ret -= comb(k, i) * solve(n, i);
        ret = ((ret % MOD) + MOD) % MOD;
    }
    ret *= modInv(k);
    ret %= MOD;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    combDP = vector<vector<ll>>(60, vector<ll>(60, -1));
    ans = vector<ll>(100, -1);

    for(ll i = 0; i <= k; i++)
        solve(n, i);

    cout << solve(n, k);
    return 0;
}