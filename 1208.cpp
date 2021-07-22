#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, s;
	cin >> n >> s;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll v0Size = (1ll << (n / 2)), v1Size = (1ll << ((n + 1) / 2));
	vector<ll> v0(v0Size), v1(v1Size);

	for (ll i = 0; i < v0Size; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			if (i & (1ll << j))
			{
				v0[i] += v[j];
			}
		}
	}

	for (ll i = 0; i < v1Size; i++)
	{
		for (int j = 0; j < (n + 1) / 2; j++)
		{
			if (i & (1ll << j))
			{
				v1[i] += v[j + n / 2];
			}
		}
	}

	sort(v0.begin(), v0.end());
	sort(v1.begin(), v1.end());
	ll ans = 0;

	for (ll elem : v0)
	{
		auto iter = lower_bound(v1.begin(), v1.end(), -elem + s);
		if (*iter == -elem + s)
		{
			ans += upper_bound(v1.begin(), v1.end(), -elem + s) - iter;
		}
	}

	if (s == 0)
	{
		ans--;
	}

	cout << ans << '\n';

	return 0;
}