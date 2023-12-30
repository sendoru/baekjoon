#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3fffffff
using namespace std;
typedef long long ll;

int findRoot(int x, vector<int>& root)
{
	if (root[x] == x) return x;
	return root[x] = findRoot(root[x], root);
}

bool hasSameRoots(int x, int y, vector<int>& root)
{
	int xRoot = findRoot(x, root);
	int yRoot = findRoot(y, root);
	if (xRoot == yRoot) return true;
	else return false;
}

void unite(int x, int y, vector<int>& root)
{
	int xRoot = findRoot(x, root);
	int yRoot = findRoot(y, root);
	if (xRoot != yRoot)
		root[yRoot] = xRoot;
}

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

int getMaxCost(vector<vector<int>>& parentSparseTable, vector<vector<int>>& maxSparseTable, vector<int>& depths, int u, int v)
{
	int ret = -INF;
	if (depths[u] < depths[v])
		swap(u, v);
	int depthDiff = depths[u] - depths[v];
	for (int i = parentSparseTable.size() - 1; i >= 0; i--)
	{
		if (depthDiff & (1 << i))
		{
			ret = max(ret, maxSparseTable[i][u]);
			u = parentSparseTable[i][u];
		}
	}
	if (u == v)
	{
		return ret;
	}
	for (int i = parentSparseTable.size() - 1; i >= 0; i--)
	{
		if (parentSparseTable[i][u] != parentSparseTable[i][v])
		{
			ret = max(ret, maxSparseTable[i][u]);
			ret = max(ret, maxSparseTable[i][v]);
			u = parentSparseTable[i][u];
			v = parentSparseTable[i][v];
		}
	}

	ret = max(ret, maxSparseTable[0][u]);
	ret = max(ret, maxSparseTable[0][v]);
	return ret;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	// 간선들 모아둔 벡터. vector<pair<가중치, pair<시작점, 도착점> > > 형태
	vector < pair<int, pair<int, int> > > edges;

	int v, e, q;
	cin >> v >> e >> q;
	vector<int> root(v + 1);
	for (int i = 1; i <= v; i++)
	{
		root[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		edges.push_back({ 0, {0, 0} });
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	}

	vector<pair<int, pair<int, int>>> sortedEdegs = edges;
	sort(sortedEdegs.begin(), sortedEdegs.end());

	ll mstCost = 0;
	vector<pair<int, pair<int, int>>> mst;

	for (int i = 0; i < e; i++)
	{
		if (hasSameRoots(sortedEdegs[i].second.first, sortedEdegs[i].second.second, root) == false)
		{
			unite(sortedEdegs[i].second.first, sortedEdegs[i].second.second, root);
			mstCost += sortedEdegs[i].first;
			mst.push_back(sortedEdegs[i]);
		}
	}

	vector<vector<pair<int, int>>> mstGraph(v + 1);
	for (int i = 0; i < mst.size(); i++)
	{
		int v1 = mst[i].second.first, v2 = mst[i].second.second, cost = mst[i].first;
		mstGraph[v1].push_back({ v2, cost });
		mstGraph[v2].push_back({ v1, cost });
	}

	vector<int> parents(v + 1), depths(v + 1, -1), costs(v + 1);
	vector<vector<int>> parentSparseTable((int)ceil(log2(v + 1)), vector<int>(v + 1)), maxSparseTable((int)ceil(log2(v + 1)), vector<int>(v + 1));
	dfs(mstGraph, parents, depths, costs, 1, 0);
	makeParentSparseTable(parentSparseTable, parents);
	makeMaxSparseTable(maxSparseTable, parentSparseTable, costs);

	for (int i = 0; i < q; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		cout << (getMaxCost(parentSparseTable, maxSparseTable, depths, v1, v2) > w ? "Yes" : "No") << '\n';
	}

	return 0;
}
