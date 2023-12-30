#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;
constexpr int INF = 0x3fffffff;

int getMaxFlow(vector<vector<int>>& capacity, int source, int sink)
{
	int nodeCnt = capacity.size();
	vector<vector<int>> flow(nodeCnt, vector<int>(nodeCnt));
	int ret = 0;

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
		// bfs
		vector<int> parents(nodeCnt, -1);
		parents[source] = source;
		queue<int> q;
		q.push(source);
		while (!q.empty() && parents[sink] == -1)
		{
			int curNode = q.front();
			q.pop();

			for (int nextNode : adj[curNode])
			{
				if (capacity[curNode][nextNode] - flow[curNode][nextNode] > 0 && parents[nextNode] == -1)
				{
					parents[nextNode] = curNode;
					q.push(nextNode);
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
			flow[parents[curNode]][curNode] += amount;
			flow[curNode][parents[curNode]] -= amount;
		}

		ret += amount;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	cin >> n >> p;
	vector<vector<int>> capacity(2 * n + 1, vector<int>(2 * n + 1));
	for (int i = 1; i <= n; i++)
	{
		if (i <= 2)
		{
			capacity[i][i + n] = INF;
			capacity[i + n][i] = INF;
		}
		else
		{
			capacity[i][i + n] = 1;
			capacity[i + n][i] = 1;
		}
	}
	for (int i = 0; i < p; i++)
	{
		int s, e;
		cin >> s >> e;
		capacity[s + n][e] = 1;
		capacity[e + n][s] = 1;
	}
	cout << getMaxFlow(capacity, n + 1, 2);
	return 0;
}