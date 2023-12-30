#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& from, int curNode)
{
	for (int nextNode : graph[curNode])
	{
		if (from[nextNode] == -1)
		{
			from[nextNode] = curNode;
			return true;
		}
	}

	for (int nextNode : graph[curNode])
	{
		if (visited[nextNode]) continue;
		visited[nextNode] = true;
		if (dfs(graph, visited, from, from[nextNode]))
		{
			from[nextNode] = curNode;
			return true;
		}
	}


	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n * 2 + 8);
	vector<int> from(n * 2 + 8, -1);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e + n + 2);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<bool> visited(graph.size());
		if (dfs(graph, visited, from, i)) ans++;
	}
	
	cout << ans;
	return 0;
}