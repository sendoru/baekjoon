#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
constexpr int INF = 0x3fffffff;

int getMaxFlow(vector<vector<int>>& capacity, int source, int sink)
{
	int nodeCnt = capacity.size();
	vector<vector<int>> adj(capacity.size());
	for (int i = 0; i < nodeCnt; i++)
	{
		for (int j = i + 1; j < nodeCnt; j++)
		{
			if (capacity[i][j] != 0 || capacity[j][i] != 0)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int ret = 0;
	vector<vector<int>> flow(nodeCnt, vector<int>(nodeCnt));
	while (true)
	{
		vector<int> prev(nodeCnt, -1);
		queue<int> q;
		prev[source] = source;
		q.push(source);
		while (!q.empty())
		{
			int curNode = q.front();
			q.pop();
			for(int nextNode : adj[curNode])
			{
				if (capacity[curNode][nextNode] - flow[curNode][nextNode] > 0 && prev[nextNode] == -1)
				{
					prev[nextNode] = curNode;
					q.push(nextNode);
				}
			}
			if (prev[sink] != -1)
			{
				break;
			}
		}

		if (prev[sink] == -1)
		{
			break;
		}

		int amount = INF;
		for (int i = sink; i != source; i = prev[i])
		{
			amount = min(amount, capacity[prev[i]][i] - flow[prev[i]][i]);
		}
		ret += amount;
		for (int i = sink; i != source; i = prev[i])
		{
			flow[prev[i]][i] += amount;
			flow[i][prev[i]] -= amount;
		}
	}

	return ret;
}

int solve(vector<vector<int>>& sharks)
{
	int n = sharks.size();
	// 0 ~ n - 1: 먹는 상어
	// n ~ 2n - 1: 먹히는 상어
	// 2n: source
	// 2n + 1: sink
	vector<vector<int>> capacity(2 * n + 2, vector<int>(2 * n + 2));
	vector<vector<int>> adj(2 * n + 2);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sharks[i] == sharks[j])
			{
				capacity[i][j + n]++;
			}
			else if (sharks[i][0] >= sharks[j][0] && sharks[i][1] >= sharks[j][1] && sharks[i][2] >= sharks[j][2])
			{
				capacity[i][j + n]++;
			}
			else if (sharks[i][0] <= sharks[j][0] && sharks[i][1] <= sharks[j][1] && sharks[i][2] <= sharks[j][2])
			{
				capacity[j][i + n]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		capacity[2 * n][i] = 2;
		capacity[i + n][2 * n + 1] = 1;
	}

	// 살아남는 상어의 최소값 = 원래 상어 갯수 - 먹히는 상어의 최댓값
	return n - getMaxFlow(capacity, 2 * n, 2 * n + 1);
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> sharks(n, vector<int>(3));
	for (int i = 0; i < n; i++)
	{
		cin >> sharks[i][0] >> sharks[i][1] >> sharks[i][2];
	}

	cout << solve(sharks);
	return 0;
}