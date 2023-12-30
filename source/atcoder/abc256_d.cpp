#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> intervals(n);
	for (int i = 0; i < n; i++)
	{
		cin >> intervals[i].first >> intervals[i].second;
	}

	sort(intervals.begin(), intervals.end());

	vector<pair<int, int>> ans;
	ans.push_back(intervals[0]);
	for (int i = 1; i < n; i++)
	{
		if (intervals[i].first <= ans.back().second)
		{
			ans.back() = make_pair(ans.back().first, max(ans.back().second, intervals[i].second));
		}
		else
		{
			ans.push_back(intervals[i]);
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}