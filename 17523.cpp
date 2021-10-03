#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	// 
	int m, n;
	cin >> m >> n;
	int r;
	cin >> r;
	vector<int> intervals(n + 1, -r);
	for (int i = 1; i <= n; i++)
		cin >> intervals[i];

	vector<int> s(m), e(m);
	for (int i = 0; i < m; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> e[i];

	vector<pair<int, int>> toLeft, toRight, ans;
	bool valid = true;
	for (int i = 0; i < m; i++)
	{
		if (s[i] > e[i])
			toLeft.push_back({ s[i], e[i] });
		else if (s[i] < e[i])
			toRight.push_back({ s[i], e[i] });
	}

	reverse(toRight.begin(), toRight.end());

	for (int i = 0; i < toLeft.size(); i++)
	{
		while (toLeft[i].first != toLeft[i].second)
		{
			auto lb = lower_bound(intervals.begin(), intervals.end(), intervals[toLeft[i].first] - r);
			if (*lb <= intervals[toLeft[i].second])
			{
				ans.push_back({ toLeft[i].first, toLeft[i].second });
				toLeft[i].first = toLeft[i].second;
			}
			else if (*lb != intervals[toLeft[i].first])
			{
				ans.push_back({ toLeft[i].first, lb - intervals.begin() });
				toLeft[i].first = lb - intervals.begin();
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 0; i < toRight.size(); i++)
	{
		while (toRight[i].first != toRight[i].second)
		{
			auto lb = lower_bound(intervals.begin(), intervals.end(), intervals[toRight[i].first] + r);
			if (lb == intervals.end() || *lb > intervals[toRight[i].first] + r)
				lb--;
			if (*lb >= intervals[toRight[i].second])
			{
				ans.push_back({ toRight[i].first, toRight[i].second });
				toRight[i].first = toRight[i].second;
			}
			else if (*lb != intervals[toRight[i].first])
			{
				ans.push_back({ toRight[i].first, lb - intervals.begin() });
				toRight[i].first = lb - intervals.begin();
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto elem : ans) cout << elem.first << ' ' << elem.second << '\n';
	return 0;
}

