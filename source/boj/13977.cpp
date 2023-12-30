#include <iostream>
#define MOD 1000000007ll
#define MAX 4000000ll

using namespace std;
typedef long long ll;
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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fac[0] = 1;
	for (int i = 1; i <= MAX; i++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	inv[MAX] = modPow(fac[MAX], MOD - 2);
	for (int i = MAX - 1; i > 0; i--)
	{
		inv[i] = (inv[i + 1] * (i + 1ll)) % MOD;
	}
	
	ll m;
	cin >> m;
	while (m--)
	{
		ll n, k;
		cin >> n >> k;
		if (k == 0 || k == n)
		{
			cout << 1 << '\n';
			continue;
		}

		ll ans = (fac[n] * inv[k]) % MOD;
		ans = (ans * inv[n - k]) % MOD;
		cout << ans << '\n';
	}
	return 0;
}