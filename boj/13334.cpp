#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> lines(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		lines[i] = { x, y };
	}
	sort(lines.begin(), lines.end(), [](pair<int, int> a, pair<int, int> b) -> bool
		{ return a.second == b.second ? a.first > b.first : a.second < b.second; });
	int d;
	cin >> d;
	priority_queue<int, vector<int>, greater<int>> q;
	int s = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		s = lines[i].second - d;
		while (!q.empty() && q.top() < s)
		{
			q.pop();
		}
		if (lines[i].first > s)
		{
			q.push(lines[i].first);
		}
		ans = max(ans, (int)q.size());
	}
	cout << ans;
	return 0;
}