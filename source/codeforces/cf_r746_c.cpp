#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& depths, int curNode, int curDepth)
{
	depths[curNode] = curDepth;
	for (auto nextNode : graph[curNode])
	{
		if (depths[nextNode] == -1)
		{
			dfs(graph, depths, nextNode, curDepth + 1);
		}
	}
}

int treeDP(vector<vector<int>>& graph, vector<int>& nodes, vector<int>& xors, vector<int>& cutCnt, int curNode, int allXor)
{
	xors[curNode] = nodes[curNode];
	for (auto nextNode : graph[curNode])
	{
		if (xors[nextNode] == -1)
		{
			xors[curNode] ^= treeDP(graph, nodes, xors, cutCnt, nextNode, allXor);
			if (xors[nextNode] == allXor || cutCnt[nextNode]) cutCnt[curNode]++;
		}
	}
	return xors[curNode];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int allXor = 0;
		vector<int> nodes(n + 1), depths(n + 1, -1), xors(n + 1, -1);
		vector<int> cutCnt(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> nodes[i];
			allXor ^= nodes[i];
		}

		vector<vector<int>> graph(n + 1);
		for (int i = 0; i < n - 1; i++)
		{
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		if (allXor == 0)
		{
			cout << "YES\n";
			continue;
		}

		if (k < 3)
		{
			cout << "NO\n";
			continue;
		}

		treeDP(graph, nodes, xors, cutCnt, 1, allXor);

		bool ans = false;
		for (int i = 1; i <= n; i++)
		{
			if ((xors[i] == 0 && cutCnt[i]) || cutCnt[i] >= 2)
			{
				ans = true;
				break;
			}
		}

		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}