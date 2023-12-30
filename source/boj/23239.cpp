#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(void)
{
	ll w, h, l;
	cin >> w >> h >> l;
	if (h > w) swap(w, h);
	ll ans = 0;
	for (ll i = 0; i <= l; i++)
	{
		ans += 3 * (ll)(sqrtl(l * l - i * i));
	}
	ans -= l;

	if (h < l)
	{
		ll l2 = l - h;
		for (ll i = 0; i <= l2; i++)
		{
			ans += (ll)(sqrtl(l2 * l2 - i * i));
		}
	}

	if (w < l)
	{
		ll l2 = l - w;
		for (ll i = 0; i <= l2; i++)
		{
			ans += (ll)(sqrtl(l2 * l2 - i * i));
		}
	}

	if (h + w < l)
	{
		ll l2 = l - w, l3 = l - h;
		for (ll i = 1; i < max(l2, l3); i++)
		{
			if (l3 * l3 - (i + w) * (i + w) < 0 || l2 * l2 - i * i < 0) break;
			if (sqrtl(l2 * l2 - i * i) < h) break;
			ans -= min((ll)(sqrt(l3 * l3 - (i + w) * (i + w))), (ll)(sqrt(l2 * l2 - i * i)) - h);
		}
	}

	cout << ans;
	return 0;
}