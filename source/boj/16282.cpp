#include <iostream>
typedef long long ll;
using namespace std;

int main(void)
{
	ll n;
	cin >> n;
	ll ans = 0;
	while (true)
	{
		ll cnt = (ans + 1ll) * ((1ll << (ans + 1ll)) - 1ll) + ans;
		if (cnt >= n)
		{
			cout << ans;
			break;
		}
		ans++;
	}
	return 0;
}