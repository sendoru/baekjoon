#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll h, w, k;
	cin >> h >> w >> k;
	vector<int> a(h), b(w);
	for (ll i = 0; i < h; i++)
		cin >> a[i];
	for (ll i = 0; i < w; i++)
		cin >> b[i];

	ll ans = 0, totalSub = 0, requiredSub = 0;
	for (ll i = 0; i < h; i++)
	{
		ll curMod = ((-w % k) + k) % k;
		ll sub = ((curMod - a[i]) % k + k) % k;
		ans += w * (k - 1) - sub;
		totalSub += sub;
	}

	ll modSum = ans % k;
	ll targetModSum = 0;
	for (int i = 0; i < w; i++)
	{
		targetModSum = (targetModSum + b[i]) % k;
		ll curMod = ((-h % k) + k) % k;
		ll sub = ((curMod - b[i]) % k + k) % k;
		requiredSub += sub;
	}

	if (modSum == targetModSum)
	{
		if (ans - max(0ll, requiredSub - totalSub) >= 0)
		{
			cout << ans - max(0ll, requiredSub - totalSub);
		}
		else
		{
			cout << -1;
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}