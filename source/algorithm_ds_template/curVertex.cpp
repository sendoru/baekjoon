#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findBridge(vector<vector<int>>& graph, vector<int>& visited, vector<pair<int, int>>& bridge, int& vertexCnt, int parent, int curVertex)
{
	visited[curVertex] = ++vertexCnt;
	int ret = visited[curVertex];
	for (int nextVertex : graph[curVertex])
	{
		if (nextVertex == parent)
		{
			continue;
		}
		if (!visited[nextVertex])
		{
			int farthest = findBridge(graph, visited, bridge, vertexCnt, curVertex, nextVertex);
			if (farthest > visited[curVertex])
			{
				bridge.push_back({ min(curVertex, nextVertex), max(curVertex, nextVertex) });
			}
			ret = min(ret, farthest);
		}
		else
		{
			ret = min(ret, visited[nextVertex]);
		}
	}
	return ret;
}

int main(void)
{
	int v, e;
	cin >> v >> e;
	vector<vector<int>> graph(v);
	vector<int> visited(v);
	vector<pair<int, int>> bridge;
	int vertexCnt = 0;
	for (int i = 0; i < e; i++)
	{
		int start, end;
		cin >> start >> end;
		start--; end--;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 0; i < v; i++)
	{
		findBridge(graph, visited, bridge, vertexCnt, -1, 0);
	}

	sort(bridge.begin(), bridge.end());
	cout << bridge.size() << '\n';
	for (auto elem : bridge)
	{
		cout << elem.first + 1 << ' ' << elem.second + 1 << '\n';
	}

	return 0;
}