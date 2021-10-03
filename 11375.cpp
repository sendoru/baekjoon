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
	vector<vector<int>> graph(n + m + 8);
	vector<int> from(n + m + 8, -1);
	vector<vector<bool>> visited(n + 1, vector<bool>(graph.size(), 0));
	for (int i = 1; i <= n; i++)
	{
		int cnt, w;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			cin >> w;
			graph[i].push_back(w + n + 1);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dfs(graph, visited[i], from, i)) ans++;
	}

	cout << ans;
	return 0;
}