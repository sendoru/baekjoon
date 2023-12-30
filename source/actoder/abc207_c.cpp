#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<double, double>> segments(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		double l, r;
		cin >> t >> l >> r;
		if (t == 2)
			r -= 0.25;
		else if (t == 3)
			l += 0.25;
		else if (t == 4)
		{
			r -= 0.25;
			l += 0.25;
		}
		segments[i] = make_pair(l, r);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (!((segments[i].second < segments[j].first && segments[i].second < segments[j].second) ||
				(segments[j].second < segments[i].first && segments[j].second < segments[i].second)))
			{
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}