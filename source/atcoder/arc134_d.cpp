#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
typedef long long ll;
const ll MOD = 998244353;
const ll MAX = 3e5;
using namespace std;

ll fac[MAX + 1];
ll inv[MAX + 1];

ll factorial(ll n)
{
	ll ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret = (ret * i) % MOD;
	}
	return ret;
}

ll modPow(ll base, ll exp)
{
	ll ret = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			ret *= base;
			ret %= MOD;
		}
		base *= base;
		base %= MOD;
		exp /= 2;
	}
	return ret;
}

ll comb(ll n, ll k)
{
	if (k < 0 || k > n || n < 0)
	{
		return 0;
	}
	if (k == 0 || k == n)
	{
		return 1;
	}

	ll ans = (fac[n] * inv[k]) % MOD;
	ans = (ans * inv[n - k]) % MOD;
	return ans;
}

ll dupComb(ll n, ll k)
{
	return comb(n + k - 1, k);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll remainder = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		remainder += a[i];

	ll ans;
	if (a[0] >= remainder + k)
	{
		ans = 1;
		for (ll i = a[0] - remainder - 1; i >= a[0] - remainder - k + 1; i--)
		{
			ans *= i;
			ans %= MOD;
		}
		for (int i = 1; i < n; i++)
		{
			for (ll j = a[i] + k - 1; j >= a[i] + 1; j--)
			{
				ans *= j;
				ans %= MOD;
			}
		}
		ll den = 1;
		for (int i = 2; i <= k - 1; i++)
		{
			den *= i;
			den %= MOD;
		}
		ans *= modPow(modPow(den, MOD - 2), n);
		ans %= MOD;
	}
	else
	{
		ans = 0;
	}

	cout << ans;
	return 0;
}


/*
20 100
998244350 9982443 9982350 9982450 9982450 9244350 8244350 9984430 9984430 992450 36456 64841 26551 982450 63191 3603 82120 94450 71667 984430

*/