#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> bfs(vector<pair<int, int>>& elevators, int n, int s, int e)
{
	if (s == e) return {};
	vector<bool> visited(n + 1);
	vector<bool> used(elevators.size());
	deque<pair<int, vector<int>>> dq;
	for (int i = 1; i < elevators.size(); i++)
	{
		if (s >= elevators[i].first && (s - elevators[i].first) % elevators[i].second == 0)
		{
			used[i] = true;
			for (int j = elevators[i].first; j <= n; j += elevators[i].second)
			{
				if (!visited[j])
				{
					dq.push_back({ j, {i} });
					visited[j] = true;
				}
			}
		}
	}

	while (!dq.empty())
	{
		int curFloor = dq.front().first;
		vector<int> curRoute = dq.front().second;
		dq.pop_front();
		if (curFloor == e)
			return curRoute;
		for (int i = 1; i < elevators.size(); i++)
		{
			if (!used[i] && curFloor >= elevators[i].first && (curFloor - elevators[i].first) % elevators[i].second == 0)
			{
				used[i] = true;
				vector<int> nextRoute = curRoute;
				nextRoute.push_back(i);
				for (int j = elevators[i].first; j <= n; j += elevators[i].second)
				{
					if (!visited[j])
					{
						dq.push_back({ j, nextRoute });
						visited[j] = true;
					}
				}
			}
		}
	}

	return { -1 };
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> elevators(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> elevators[i].first >> elevators[i].second;
	}
	int s, e;
	cin >> s >> e;
	vector<int> ans = bfs(elevators, n, s, e);
	if (ans[0] == -1) cout << -1;
	else
	{
		cout << ans.size() << '\n';
		for (auto elem : ans)
		{
			cout << elem << '\n';
		}
	}

	return 0;
}