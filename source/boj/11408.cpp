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
	/*
	* 소스: 0번
	* 각 직원: 1 ~ n번
	* 각 일: n + 1 ~ n + m번
	* 싱크: n + m + 1번
	* 정점 갯수: n + m + 2
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> capacity(n + m + 2, vector<int>(n + m + 2));
	vector<vector<int>> costs(n + m + 2, vector<int>(n + m + 2));
	for (int i = 1; i <= n; i++)
	{
		capacity[0][i] = 1;
		int cnt;
		cin >> cnt;
		while (cnt--)
		{
			int work, cost;
			cin >> work >> cost;
			capacity[i][work + n] = 1;
			costs[i][work + n] = cost;
			costs[work + n][i] = -cost;
		}
	}

	for (int i = n + 1; i <= n + m; i++)
	{
		capacity[i][n + m + 1] = 1;
	}
	auto ans = getMCMF(capacity, costs, 0, n + m + 1);
	cout << ans.second << '\n' << ans.first;

	return 0;
}