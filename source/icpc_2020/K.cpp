#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
constexpr int INF = 0x3fffffff;

int solve(vector<vector<int>>& city)
{
	int n = city.size(), m = city[0].size();
	vector<int> dist(n * m, INF);
	dist[0] = 0;
	// 인접 배열 형태로 저장
	// 좌표가(i, j)인 노드의 번호는 m * i + j
	vector<vector<pair<int, int>>> graph(n * m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (city[i][j] == -1)
			{
				continue;
			}
			if (i != 0)
			{
				graph[m * (i - 1) + j].push_back({ city[i][j], m * i + j });
			}
			if (i != n - 1)
			{
				graph[m * (i + 1) + j].push_back({ city[i][j], m * i + j });
			}
			if (j != 0)
			{
				graph[m * i + j - 1].push_back({ city[i][j], m * i + j });
			}
			if (j != m - 1)
			{
				graph[m * i + j + 1].push_back({ city[i][j], m * i + j });
			}
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 0 });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (dist[curNode] < cost)
		{
			continue;
		}

		for (auto edge : graph[curNode])
		{
			int nextCost = edge.first;
			int nextNode = edge.second;
			if (dist[nextNode] > dist[curNode] + nextCost)
			{
				dist[nextNode] = dist[curNode] + nextCost;
				pq.push(edge);
			}
		}
	}


	return dist.back();
}


int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> city(n, vector<int> (m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> city[i][j];
		}
	}

	if (city[0][0] == -1)
	{
		cout << -1;
		return 0;
	}
	int ans = solve(city);
	cout << (ans == INF ? -1 : ans + city[0][0]);
	return 0;
}