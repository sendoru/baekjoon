#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
typedef long double ld;
const ld INF = 1e9;
using namespace std;

ld dist(pair<ld, ld>& a, pair<ld, ld>& b)
{
	return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<bool> lighted(n);
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		temp--;
		lighted[temp] = true;
	}

	vector<pair<ld, ld>> coor(n);
	for (int i = 0; i < n; i++)
		cin >> coor[i].first >> coor[i].second;


	ld ans = 0.;
	for (int i = 0; i < n; i++)
	{
		if (lighted[i])
			continue;
		ld curLen = INF;
		for (int j = 0; j < n; j++)
		{
			if (lighted[j])
			{
				curLen = min(curLen, dist(coor[i], coor[j]));
			}
		}
		ans = max(ans, curLen);
	}

	cout.precision(14);
	cout << ans;
	return 0;
}