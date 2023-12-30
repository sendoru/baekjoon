#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define DEBUG
#undef DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;

ll dist(pair<ll, ll>& a, pair<ll, ll>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		vector<ll> dists = { a, b, c };
		sort(dists.begin(), dists.end());
		if (dists[2] > dists[1] + dists[0] || dists[2] % 2 != (dists[1] + dists[0]) % 2)
		{
			cout << "-1\n";
			continue;
		}

		vector<pair<ll, ll>> dots(3);
		dots[0] = { 1, 1 };
		if (dists[0] + dists[1] == dists[2])
		{
			dots[1] = { dists[0] + 1, 1 };
			dots[2] = { dists[2] / 2 + dists[2] % 2 + 1, dists[2] / 2 + 1};
		}
		else
		{
			ll w, h;
			w = min((ll)8e8 - 1, dists[2]);
			h = (dists[0] + dists[1] + dists[2]) / 2 - w;
			dots[1] = { w + 1, (dists[2] - w) + 1 };
			dots[2] = { (dists[1] - h) + 1, h + 1 };
			if (h >= 8e8)
			{
				cout << "-1\n";
				continue;
			}
		}

		bool printed = false;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (dist(dots[i], dots[j]) == a && dist(dots[j], dots[k]) == b && dist(dots[k], dots[i]) == c)
					{
						cout << dots[i].first << ' ' << dots[i].second << ' ';
						cout << dots[j].first << ' ' << dots[j].second << ' ';
						cout << dots[k].first << ' ' << dots[k].second << ' ';
						cout << '\n';
						printed = true;
						break;
					}
				}
				if (printed)
					break;
			}
			if (printed)
				break;
		}
	}
}