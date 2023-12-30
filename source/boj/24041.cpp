#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll MAX = 2e9;

ll solve(vector<vector<ll>>& ing, ll g, ll k)
{
	ll ans = 0;
	ll l = 0, r = MAX;
	vector<vector<ll>> unnecessary;

	while (l <= r)
	{
		ll m = (l + r) / 2;
		ll curGerms = 0;
		ll removed = 0;
		vector<pair<ll, ll>> delta;
		for (auto elem : ing)
		{
			delta.push_back({ elem[0] * max(1ll, (m - elem[1])), elem[2] });
		}
		sort(delta.begin(), delta.end(), greater<pair<ll, ll>>());
		for (auto elem : delta)
		{
			if (elem.second == 1 && removed < k)
			{
				removed++;
			}
			else
			{
				curGerms += elem.first;
			}
		}
		if (curGerms <= g)
		{
			ans = max(ans, m);
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}

	return ans;
}

int main(void)
{
	ll n, g, k;
	cin >> n >> g >> k;
	vector<vector<ll>> ing(n, vector<ll>(3));
	for (int i = 0; i < n; i++)
	{
		cin >> ing[i][0] >> ing[i][1] >> ing[i][2];
	}
	cout << solve(ing, g, k);
	return 0;
}