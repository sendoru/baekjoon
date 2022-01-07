#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define MAX 222232

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
	int n, q;
	cin >> n >> q;
	vector<int> parents(n + 1, 0), depths(n + 1, -1), trailS(n + 1), trailE(n + 1), trailCnt(n + 1);
	vector<vector<int>> graph(n + 1), nodesByDepth(n + 1);
	graph[1].push_back(0);
	graph[0].push_back(1);

	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	dfs(graph, parents, depths, 0, 0);
	for (int i = 1; i <= n; i++)
	{
		nodesByDepth[depths[i]].push_back(i);
	}

	vector<vector<int>> sparseTable(ceil((int)log2(n + 1)), vector<int>(n + 1));
	makeSparseTable(sparseTable, parents);

	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		int abLCA = getLCA(sparseTable, depths, a, b);

		if (abLCA == a)
		{
			trailS[b]++;
			trailE[a]++;
		}
		else if (abLCA == b)
		{
			trailS[a]++;
			trailE[b]++;
		}
		else
		{
			trailS[a]++;
			trailS[b]++;
			trailE[abLCA]++;
			trailCnt[abLCA]--;
		}

	}

	int maxCnt = -1;
	pair<int, int> ans = { MAX, MAX };
	for (int i = nodesByDepth.size() - 1; i >= 0; i--)
	{
		for (auto curNode : nodesByDepth[i])
		{
			trailCnt[curNode] += trailS[curNode];
			for (auto child : graph[curNode])
			{
				if (child != parents[curNode])
				{
					trailCnt[curNode] += trailCnt[child];
					trailCnt[curNode] -= trailE[child];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (trailCnt[i] > maxCnt)
		{
			ans = { min(i, parents[i]), max(i, parents[i]) };
			maxCnt = trailCnt[i];
		}
		else if (trailCnt[i] == maxCnt)
		{
			if (make_pair(min(i, parents[i]), max(i, parents[i])) < ans)
			{
				ans = { min(i, parents[i]), max(i, parents[i]) };
			}
		}
	}
	
	cout << maxCnt;
	return 0;
}