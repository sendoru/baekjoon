#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;


ll modPow(ll base, ll exp)
{
    if (exp == 0) return 1;
    ll temp = modPow(base, exp / 2);
    if (exp & 1) return (((temp * temp) % MOD) * base) % MOD;
    return temp * temp % MOD;
}

ll fact(ll n)
{
    if (n < 0) return 0;
    if (n < 2) return 1;
    ll ret = 1;
    for (ll i = 2; i <= n; i++)
    {
        ret = ret * i % MOD;
    }
    return ret;
}

ll modInv(ll n)
{
    return modPow(n, MOD - 2);
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<ll> vSum(n);
        vSum[0] = v[0];
        for (int i = 1; i < n; i++)
            vSum[i] = vSum[i - 1] + v[i];

        ll ans = 0;
        if (k == 1)
            ans = 1;
        else if (vSum.back() % k == 0)
        {
            ll bucketSum = vSum.back() / k;
            if (bucketSum == 0)
            {
                ll zeroCnt = count(vSum.begin(), vSum.end(), 0ll);
                // (zeroCnt - 1) C (k - 1)
                if (zeroCnt >= k)
                    ans = ((fact(zeroCnt - 1) * modInv(fact(k - 1)) % MOD) * modInv(fact(zeroCnt - k))) % MOD;
            }

            else
            {
                /*
                if (bucketSum < 0)
                {
                    for (auto& elem : vSum)
                        elem *= -1;
                    bucketSum *= -1;
                }
                */
                vector<ll> cnt(k);
                for (int i = 0; i < vSum.size(); i++)
                {
                    if (vSum[i] % bucketSum == 0 && vSum[i] / bucketSum == 1)
                    {
                        cnt[1]++;
                        cnt[1] %= MOD;
                    }
                    else if (vSum[i] % bucketSum == 0 && vSum[i] / bucketSum >= 2 && abs(vSum[i]) < abs(vSum.back()))
                    {
                        cnt[vSum[i] / bucketSum] += cnt[vSum[i] / bucketSum - 1];
                        cnt[vSum[i] / bucketSum] %= MOD;
                    }
                }

                ans = cnt.back();
            }
        }
        cout << "Case #" << t << '\n';
        cout << ans << '\n';
    }

    return 0;
}