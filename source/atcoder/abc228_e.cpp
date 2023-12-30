#include <iostream>
typedef long long ll;
using namespace std;
constexpr ll MOD = 998244353;

ll modPow(ll base, ll exp, ll mod)
{
	if (exp == 0) return 1;
	if (exp % 2 == 0) return (modPow(base, exp / 2, mod) * modPow(base, exp / 2, mod)) % mod;
	else return (modPow(base, exp - 1, mod) * (base % mod)) % mod;
}

int main(void)
{
	ll n, k, m;
	cin >> n >> k >> m;
	if (m % MOD == 0)
	{
		cout << 0;
		return 0;
	}
	// 일단 정답은 m^(k^n)
	ll exp = modPow(k, n, MOD - 1ll);
	ll ans = modPow(m, exp, MOD);
	cout << ans;
	return 0;
}