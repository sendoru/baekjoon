#include <vector>
#include <iostream>
typedef long long ll;
constexpr ll MOD = 1'000'000'007;
using namespace std;

ll modPow(ll base, ll exp, ll mod)
{
	if (exp == 0) return 1;
	else if (exp % 2 == 0) return (modPow(base, exp / 2, mod) * modPow(base, exp / 2, mod)) % mod;
	else return (modPow(base, exp - 1, mod) * base) % mod;
}

int main(void)
{
	ll k, n;
	cin >> k >> n;
	ll ans = 1;
	// 정답 : (n + k) C (k + 1)
	// n부터 n + k까지 곱하고 2부터 k + 1까지 나누기
	for (ll i = n; i <= n + k; i++)
	{
		ans *= i;
		ans %= MOD;
	}
	for (ll i = 2; i <= k + 1; i++)
	{
		ans *= modPow(i, MOD - 2, MOD);
		ans %= MOD;
	}

	cout << ans;
	return 0;
}