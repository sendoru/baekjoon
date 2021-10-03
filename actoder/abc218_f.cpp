#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> ans(m);
	vector<set<pair<int, int>>> adjList(n + 1);
	vector<pair<int, int>> edges(m);
	vector<int> shortestPath;
	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].first >> edges[i].second;
		adjList[edges[i].first].insert({ edges[i].second, i });
	}

	// 일단 bfs를 돌려서 최단경로에 있는 간선을 파악함
	vector<int> dist(n + 1, -1);
	queue<int> q1;
	queue<vector<int>> q2;
	dist[1] = 0;
	q1.push(1);
	q2.push({});
	while (!q1.empty())
	{
		int curNode = q1.front();
		vector<int> curPath = q2.front();
		q1.pop(); q2.pop();
		if (curNode == n)
		{
			shortestPath = curPath;
			break;
		}
		for (auto elem : adjList[curNode])
		{
			int nextNode = elem.first, edgeNo = elem.second;
			if (dist[nextNode] == -1)
			{
				dist[nextNode] = dist[curNode] + 1;
				q1.push(nextNode);
				curPath.push_back(edgeNo);
				q2.push(curPath);
				curPath.pop_back();
			}
		}
	}

	if (dist[n] == -1)
	{
		for (int i = 0; i < m; i++)
		{
			cout << -1 << '\n';
		}
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		ans[i] = dist[n];
	}

	for (int i = 0; i < shortestPath.size(); i++)
	{
		int curEdge = shortestPath[i];
		adjList[edges[curEdge].first].erase({ edges[curEdge].second , curEdge });

		for (int i = 0; i <= n; i++)
		{
			dist[i] = -1;
		}
		while (!q1.empty())
		{
			q1.pop();
		}
		dist[1] = 0;
		q1.push(1);
		while (!q1.empty())
		{
			int curNode = q1.front();
			q1.pop();
			if (curNode == n)
			{
				break;
			}
			for (auto elem : adjList[curNode])
			{
				int nextNode = elem.first, edgeNo = elem.second;
				if (dist[nextNode] == -1)
				{
					dist[nextNode] = dist[curNode] + 1;
					q1.push(nextNode);
				}
			}
		}
		ans[curEdge] = dist[n];
		adjList[edges[curEdge].first].insert({ edges[curEdge].second , curEdge });
	}

	for (int i = 0; i < m; i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}