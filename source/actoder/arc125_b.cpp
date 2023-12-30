#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll MOD = 998244353;

int main(void)
{
	ll n;
	ll ans = 0;
	cin >> n;
	for (ll k = 1; k <= n; k++)
	{
		if ((n - k * k) < 0)
		{
			break;
		}
		else
		{
			ans += (n - k * k) / (2 * k) + 1;
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}