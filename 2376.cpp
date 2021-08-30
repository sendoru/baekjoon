#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& graph, int start, int end)
{
	vector<bool> visited(graph.size());
	queue<pair<int, int>> q;
	visited[start] = true;
	q.push({ start, 0 });
	while (!q.empty())
	{
		int curNode = q.front().first;
		int curDist = q.front().second;
		if (curNode == end)
		{
			return curDist;
		}
		q.pop();
		for (int nextNode : graph[curNode])
		{
			if (!visited[nextNode])
			{
				visited[nextNode] = true;
				q.push({ nextNode, curDist + 1 });
			}
		}
	}
	return -1;
}

int main(void)
{
	int n;
	cin >> n;
	// dist[i] := i번째 정점과 i + 1번째 정점의 거리
	vector<int> dist(n + 1);
	vector<vector<int>> graph(n + 1);
	for (int i = 1; i < n; i++)
	{
		cin >> dist[i];
	}
	int nodeCnt = n;
	for (int i = 1; i < n; i++)
	{
		int curNode = i;
		for (int j = 1; j <= dist[i]; j++)
		{
			if (j == dist[i])
			{
				graph[curNode].push_back(i + 1);
				graph[i + 1].push_back(curNode);
			}
			else if (graph[curNode].size() == 0 || (graph[curNode].size() == 1 && curNode > n) || graph[curNode].size() == 2)
			{
				graph[curNode].push_back(++nodeCnt);
				graph.push_back({ curNode });
				curNode = nodeCnt;
			}
			else if ((graph[curNode].size() == 1 && curNode <= n) || graph[curNode].size() == 3)
			{
				curNode = graph[curNode][0];
			}
		}
	}

	int a, b;
	cin >> a >> b;
	cout << bfs(graph, a, b) << '\n';
	return 0;

}