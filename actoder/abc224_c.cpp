#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll area(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
	return  (a.first * b.second + b.first * c.second + c.first * a.second) - (a.second * b.first + b.second * c.first + c.second * a.first);
}

int main(void)
{
	int n;
	cin >> n;
	vector<pair<ll, ll>> dots(n);
	for (int i = 0; i < n; i++)
		cin >> dots[i].first >> dots[i].second;

	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (area(dots[i], dots[j], dots[k]) != 0)
				{
					ans++;
				}
			}
		}
	}

	cout << ans;
	return 0;
}