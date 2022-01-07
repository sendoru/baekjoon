#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define MAX 100010

using namespace std;
typedef long long ll;

void dfs(vector<vector<int>>& graph, vector<int>& parents, vector<int>& depths, int curNode, int curDepth)
{
	depths[curNode] = curDepth;
	for (int nextNode : graph[curNode])
	{
		if (depths[nextNode] == -1)
		{
			parents[nextNode] = curNode;
			dfs(graph, parents, depths, nextNode, curDepth + 1);
		}
	}
}

void makeSparseTable(vector<vector<int>>& sparseTable, vector<int>& parents)
{
	for (int i = 0; i < parents.size(); i++)
	{
		sparseTable[0][i] = parents[i];
	}
	for (int i = 1; i < sparseTable.size(); i++)
	{
		for (int j = 0; j < sparseTable[i].size(); j++)
		{
			sparseTable[i][j] = sparseTable[i - 1][sparseTable[i - 1][j]];
		}
	}
}

int getLCA(vector<vector<int>>& sparseTable, vector<int>& depths, int u, int v)
{
	if (depths[u] < depths[v])
		swap(u, v);
	int depthDiff = depths[u] - depths[v];
	for (int i = sparseTable.size() - 1; i >= 0; i--)
	{
		if (depthDiff & (1 << i))
		{
			u = sparseTable[i][u];
		}
	}
	if (u == v)
	{
		return v;
	}
	for (int i = sparseTable.size() - 1; i >= 0; i--)
	{
		if (sparseTable[i][u] != sparseTable[i][v])
		{
			u = sparseTable[i][u];
			v = sparseTable[i][v];
		}
	}
	return sparseTable[0][v];
}


int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1);
	vector<int> parents(n + 1);
	vector<vector<int>> sparseTable(18, vector<int>(n + 1));
	vector<int> depths(n + 1, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(graph, parents, depths, 1, 0);
	parents[1] = 1;
	makeSparseTable(sparseTable, parents);

	int m;
	cin >> m;
	while (m--)
	{
		int r, u, v;
		cin >> r >> u >> v;
		int lca1 = getLCA(sparseTable, depths, u, v);
		int lca2 = getLCA(sparseTable, depths, r, u);
		int lca3 = getLCA(sparseTable, depths, r, v);
		int lca;
		if (depths[lca1] >= depths[lca2] && depths[lca1] >= depths[lca3])
			lca = lca1;
		else if (depths[lca2] >= depths[lca1] && depths[lca2] >= depths[lca3])
			lca = lca2;
		else
			lca = lca3;
		cout << lca << '\n';
	}

	return 0;
}