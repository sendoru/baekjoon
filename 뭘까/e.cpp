#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int bfs(vector<set<int>>& graph, int startNode)
{
	vector<bool> visited(graph.size());
	queue<int> q;
	int ret = 0;
	visited[startNode] = true;
	q.push(startNode);
	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (int nextNode : graph[curNode])
		{
			if (!visited[nextNode])
			{
				q.push(nextNode);
				visited[nextNode] = true;
				ret++;
			}
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<set<int>> graph(n + 1, set<int>()), reversedGrpah(n + 1, set<int>());
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].insert(e);
		reversedGrpah[e].insert(s);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << max(0, n - bfs(graph, i) - bfs(reversedGrpah, i) - 1) << '\n';
	}
	return 0;
}