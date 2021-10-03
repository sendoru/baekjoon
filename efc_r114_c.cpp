#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll INF = 2e18;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<ll> heroes(n);
	for (int i = 0; i < n; i++)
		cin >> heroes[i];
	sort(heroes.begin(), heroes.end());
	ll strSum = 0;
	for (ll elem : heroes) strSum += elem;

	int m;
	cin >> m;
	vector<pair<ll, ll>> dragons(m);
	for (int i = 0; i < m; i++)
		cin >> dragons[i].first >> dragons[i].second;

	for (int i = 0; i < m; i++)
	{
		ll ans = INF;

		auto iter = lower_bound(heroes.begin(), heroes.end(), dragons[i].first);
		if (iter != heroes.end() && *iter == dragons[i].first)
		{
			ans = max(0ll, dragons[i].second - (strSum - *iter));
		}
		else
		{
			if (iter != heroes.end())
			{
				ans = min(ans, max(0ll, dragons[i].second - (strSum - *iter)));
			}
			iter = lower_bound(heroes.begin(), heroes.end(), dragons[i].first - 1);
			if (iter != heroes.end() && *iter == dragons[i].first - 1)
			{
				ans = min(ans, max(0ll, dragons[i].second - (strSum - *iter)) + 1);
			}
			else
			{
				if (iter != heroes.begin())
				{
					iter--;
					ans = min(ans, max(0ll, dragons[i].second - (strSum - *iter)) + (dragons[i].first - *iter));
				}
			}
		}

		cout << max(0ll, ans) << '\n';
	}
	return 0;
}