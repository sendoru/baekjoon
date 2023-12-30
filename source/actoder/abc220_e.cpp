#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

ll modPow(ll base, ll exp)
{
	if (exp == 0) return 1;
	if (exp & 1) return ((modPow(base, exp / 2) % MOD) * (modPow(base, exp / 2) % MOD) * base) % MOD;
	return ((modPow(base, exp / 2) % MOD) * (modPow(base, exp / 2) % MOD)) % MOD;
}

int main(void)
{
	vector<ll> squares(1000001);
	squares[0] = 1;
	for (int i = 1; i < squares.size(); i++)
	{
		squares[i] = (squares[i - 1] * 2) % MOD;
	}

	ll n, d;
	cin >> n >> d;
	if (d > (n - 1) * 2)
	{
		cout << 0;
		return 0;
	}

	ll ans = 0;
	if (d <= (n - 1))
	{
		ans += (squares[d + 1] * ((squares[n - d] - 1) % MOD)) % MOD;
	}
	for (ll l = 1; l <= d / 2; l++)
	{
		ll r = d - l;
		if (r > n - 1) continue;
		if (r != l)
		{
			ans += ((((((squares[l] % MOD) * ((squares[n - r] - 1) % MOD)) % MOD) * (squares[r] % MOD)) % MOD)) % MOD;
		}
		else
		{
			ans += ((((((squares[l] % MOD) * ((squares[n - r] - 1) % MOD)) % MOD) * (squares[r - 1] % MOD)) % MOD)) % MOD;
		}
		ans %= MOD;
	}

	cout << ans;
	return 0;
}