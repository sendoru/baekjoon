#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;
constexpr int INF = 0x3fffffff;

pair<int, int> getMCMF(vector<vector<int>>& capacity, vector<vector<int>>& costs, int source, int sink)
{
	int nodeCnt = capacity.size();
	vector<vector<int>> flow(nodeCnt, vector<int>(nodeCnt));
	int minCost = 0, maxFlow = 0;

	vector<vector<int>> adj(nodeCnt);
	for (int i = 0; i < nodeCnt; i++)
	{
		for (int j = i; j < nodeCnt; j++)
		{
			if (capacity[i][j] != 0 || capacity[j][i] != 0)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	while (true)
	{
		// spfa
		vector<int> parents(nodeCnt, -1), dists(nodeCnt, INF);
		vector<bool> inQ(nodeCnt, false);
		parents[source] = source;
		queue<int> q;
		q.push(source);
		inQ[source] = true;
		dists[source] = 0;
		while (!q.empty())
		{
			int curNode = q.front();
			q.pop();
			inQ[curNode] = false;

			for (int nextNode : adj[curNode])
			{
				if (capacity[curNode][nextNode] - flow[curNode][nextNode] > 0 && dists[nextNode] > dists[curNode] + costs[curNode][nextNode])
				{
					parents[nextNode] = curNode;
					dists[nextNode] = dists[curNode] + costs[curNode][nextNode];
					if (!inQ[nextNode])
					{
						q.push(nextNode);
						inQ[nextNode] = true;
					}
				}
			}
		}

		if (parents[sink] == -1)
		{
			break;
		}

		int amount = INF + 2;
		for (int curNode = sink; curNode != source; curNode = parents[curNode])
		{
			amount = min(capacity[parents[curNode]][curNode] - flow[parents[curNode]][curNode], amount);
		}

		for (int curNode = sink; curNode != source; curNode = parents[curNode])
		{
			minCost += amount * costs[parents[curNode]][curNode];
			flow[parents[curNode]][curNode] += amount;
			flow[curNode][parents[curNode]] -= amount;
		}

		maxFlow += amount;
	}
	return { minCost, maxFlow };
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int v, e;
		cin >> v >> e;

		if (cin.eof()) break;

		vector<vector<int>> capacity(2 * v + 1, vector<int>(2 * v + 1));
		vector<vector<int>> costs(2 * v + 1, vector<int>(2 * v + 1));
		for (int i = 1; i <= v; i++)
		{
			if (i == 1 || i == v)
			{
				capacity[i][i + v] = 2;
				capacity[i + v][i] = 2;
			}
			else
			{
				capacity[i][i + v] = 1;
				capacity[i + v][i] = 1;
			}
		}
		for (int i = 0; i < e; i++)
		{
			int start, end, cost;
			cin >> start >> end >> cost;
			capacity[start + v][end] = 1;
			costs[start + v][end] += cost;
			costs[end][start + v] -= cost;
		}

		auto ans = getMCMF(capacity, costs, 1, v);
		cout << ans.first << '\n';

	}

	return 0;
}