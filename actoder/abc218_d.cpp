#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> dots(n);
	for (int i = 0; i < n; i++)
	{
		cin >> dots[i].first >> dots[i].second;
	}
	sort(dots.begin(), dots.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dots[i].first < dots[j].first
				&& dots[i].second < dots[j].second)
			{
				auto d1 = *lower_bound(dots.begin(), dots.end(), make_pair(dots[i].first, dots[j].second)),
					d2 = *lower_bound(dots.begin(), dots.end(), make_pair(dots[j].first, dots[i].second));
				if (d1 == make_pair(dots[i].first, dots[j].second) && d2 == make_pair(dots[j].first, dots[i].second))
					ans++;
			}
		}
	}
	cout << ans;
	return 0;
}