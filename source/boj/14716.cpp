#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int INF = 0x3fffffff;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int py, qy;
	cin >> py >> qy;
	vector<int> p(n), q(m);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < m; i++) cin >> q[i];

	int minDist = INF, minCnt = 1;
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	for (int px : p)
	{
		auto iter = lower_bound(q.begin(), q.end(), px);
		if (iter != q.end())
		{
			if (abs(px - *iter) + abs(py - qy) < minDist)
			{
				minDist = abs(px - *iter) + abs(py - qy);
				minCnt = 1;
			}
			else if (abs(px - *iter) + abs(py - qy) == minDist)
			{
				minCnt++;
			}
		}
		if (iter != q.begin())
		{
			iter--;
			if (abs(px - *iter) + abs(py - qy) < minDist)
			{
				minDist = abs(px - *iter) + abs(py - qy);
				minCnt = 1;
			}
			else if (abs(px - *iter) + abs(py - qy) == minDist)
			{
				minCnt++;
			}
		}
	}

	cout << minDist << ' ' << minCnt;
	return 0;
}