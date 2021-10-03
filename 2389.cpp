#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double dist(pair<double, double> x, pair<double, double> y)
{
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(3);

	int n;
	cin >> n;
	vector<pair<double, double>> dots(n);
	pair<double, double> ans;
	double maxDist;
	for (int i = 0; i < n; i++)
	{
		cin >> dots[i].first >> dots[i].second;
		ans.first += dots[i].first;
		ans.second += dots[i].second;
	}

	ans.first /= n;
	ans.second /= n;

	double eta = 0.1;
	for (int i = 0; i < 50000; i++)
	{
		int idx = 0;
		maxDist = dist(ans, dots[0]);
		for (int j = 0; j < n; j++)
		{
			double curDist = dist(ans, dots[j]);
			if (curDist > maxDist)
			{
				idx = j;
				maxDist = curDist;
			}
		}
		ans.first += (dots[idx].first - ans.first) * eta;
		ans.second += (dots[idx].second - ans.second) * eta;
		eta *= 0.999;
	}

	cout << fixed << ans.first << ' ' << ans.second << '\n' << sqrt(maxDist);
	return 0;
}