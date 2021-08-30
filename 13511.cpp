#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define MAX 100010

using namespace std;
typedef long long ll;

void dfs(vector<vector<pair<int, int>>>& graph, vector<int>& parents, vector<int>& depths, vector<ll>& costs, int curNode, int curDepth, ll curCost)
{
	depths[curNode] = curDepth;
	costs[curNode] = curCost;
	for (auto next : graph[curNode])
	{
		int nextNode = next.first, edgeCost = next.second;
		if (depths[nextNode] == -1)
		{
			parents[nextNode] = curNode;
			dfs(graph, parents, depths, costs, nextNode, curDepth + 1, curCost + edgeCost);
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

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> parents(n + 1);
	vector<vector<int>> sparseTable(18, vector<int>(n + 1));
	vector<int> depths(n + 1, -1);
	vector<ll> costs(n + 1, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	dfs(graph, parents, depths, costs, 1, 0, 0);
	parents[1] = 1;
	makeSparseTable(sparseTable, parents);

	int m;
	cin >> m;
	while (m--)
	{
		int q, u, v, tempU, tempV, lca;
		cin >> q >> u >> v;
		tempU = u, tempV = v;
		if (depths[tempU] > depths[tempV])
		{
			int temp = tempU;
			tempU = tempV;
			tempV = temp;
		}
		int depthDiff = depths[tempV] - depths[tempU];
		for (int i = 0; i < sparseTable.size(); i++)
		{
			if (depthDiff & (1 << i))
			{
				tempV = sparseTable[i][tempV];
			}
		}
		if (tempU != tempV)
		{
			for (int i = sparseTable.size() - 1; i >= 0; i--)
			{
				if (sparseTable[i][tempU] != sparseTable[i][tempV])
				{
					tempU = sparseTable[i][tempU];
					tempV = sparseTable[i][tempV];
				}
			}
			if (tempU != tempV)
			{
				lca = parents[tempU];
			}
			else
			{
				lca = tempU;
			}
		}
		else
		{
			lca = tempU;
		}
		

		if (q == 1)
		{
			cout << costs[u] + costs[v] - (2 * costs[lca]) << '\n';
		}
		else
		{
			int k;
			cin >> k;
			if (k <= depths[u] - depths[lca] + 1)
			{
				k--;
				for (int i = 0; i < sparseTable.size(); i++)
				{
					if (k & (1 << i))
						u = sparseTable[i][u];
				}
				cout << u << '\n';
			}
			else
			{
				k--;
				k = depths[u] + depths[v] - 2 * depths[lca] - k;
				for (int i = 0; i < sparseTable.size(); i++)
				{
					if (k & (1 << i))
					{
						v = sparseTable[i][v];
					}
				}
				cout << v << '\n';
			}
		}
	}

	return 0;
}