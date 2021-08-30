#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define MAX 100010
#define INF 0x3fffffff

using namespace std;
typedef long long ll;

void dfs(vector<vector<pair<int, int>>>& graph, vector<int>& parents, vector<int>& depths, vector<int>& costs, int curNode, int curDepth)
{
	depths[curNode] = curDepth;
	for (auto next : graph[curNode])
	{
		int nextNode = next.first, edgeCost = next.second;
		if (depths[nextNode] == -1)
		{
			parents[nextNode] = curNode;
			costs[nextNode] = edgeCost;
			dfs(graph, parents, depths, costs, nextNode, curDepth + 1);
		}
	}
}

void makeParentSparseTable(vector<vector<int>>& sparseTable, vector<int>& parents)
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

void makeMinSparseTable(vector<vector<int>>& minSparseTable, vector<vector<int>>& parentSparseTable, vector<int>& costs)
{
	costs[0] = costs[1] = INF;
	for (int i = 0; i < costs.size(); i++)
	{
		minSparseTable[0][i] = costs[i];
	}
	for (int i = 1; i < minSparseTable.size(); i++)
	{
		for (int j = 0; j < minSparseTable[i].size(); j++)
		{
			minSparseTable[i][j] = min(minSparseTable[i - 1][j], minSparseTable[i - 1][parentSparseTable[i - 1][j]]);
		}
	}
}

void makeMaxSparseTable(vector<vector<int>>& maxSparseTable, vector<vector<int>>& parentSparseTable, vector<int>& costs)
{
	costs[0] = costs[1] = -INF;
	for (int i = 0; i < costs.size(); i++)
	{
		maxSparseTable[0][i] = costs[i];
	}
	for (int i = 1; i < maxSparseTable.size(); i++)
	{
		for (int j = 0; j < maxSparseTable[i].size(); j++)
		{
			maxSparseTable[i][j] = max(maxSparseTable[i - 1][j], maxSparseTable[i - 1][parentSparseTable[i - 1][j]]);
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
	int height = (int)(ceil(log2(n)));
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> parents(n + 1);
	vector<vector<int>> parentSparseTable(height, vector<int>(n + 1));
	vector<vector<int>> minSparseTable(height, vector<int>(n + 1));
	vector<vector<int>> maxSparseTable(height, vector<int>(n + 1));
	vector<int> depths(n + 1, -1);
	vector<int> costs(n + 1, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	dfs(graph, parents, depths, costs, 1, 0);
	parents[1] = 1;
	makeParentSparseTable(parentSparseTable, parents);
	makeMinSparseTable(minSparseTable, parentSparseTable, costs);
	makeMaxSparseTable(maxSparseTable, parentSparseTable, costs);

	int k;
	cin >> k;
	while (k--)
	{
		int d, e, tempD, tempE, depthDiff, lca;
		cin >> d >> e;
		tempD = d, tempE = e;
		if (depths[d] < depths[e])
		{
			swap(tempD, tempE);
		}
		depthDiff = depths[tempD] - depths[tempE];
		while (depths[tempD] != depths[tempE])
		{
			for (int i = 0; i < height; i++)
			{
				if (depthDiff & (1 << i)) tempD = parentSparseTable[i][tempD];
			}
		}
		if (tempD == tempE) lca = tempD;
		else
		{
			for (int i = height - 1; i >= 0; i--)
			{
				if (parentSparseTable[i][tempD] != parentSparseTable[i][tempE])
				{
					tempD = parentSparseTable[i][tempD];
					tempE = parentSparseTable[i][tempE];
				}
			}
			lca = parents[tempD];
		}

		int minLen = INF, maxLen = -INF;
		int dDepthDiff = depths[d] - depths[lca];
		for (int i = 0; i < height; i++)
		{
			if (dDepthDiff & (1 << i))
			{
				minLen = min(minLen, minSparseTable[i][d]);
				maxLen = max(maxLen, maxSparseTable[i][d]);
				d = parentSparseTable[i][d];
			}
		}
		int eDepthDiff = depths[e] - depths[lca];
		for (int i = 0; i < height; i++)
		{
			if (eDepthDiff & (1 << i))
			{
				minLen = min(minLen, minSparseTable[i][e]);
				maxLen = max(maxLen, maxSparseTable[i][e]);
				e = parentSparseTable[i][e];
			}
		}
		
		cout << minLen << ' ' << maxLen << "\n";
	}
	return 0;
}