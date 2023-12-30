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

			for (int nextNode = 0; nextNode < nodeCnt; nextNode++)
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

		int amount = INF;
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
	int n, p;
	cin >> n >> p;
	vector<vector<int>> capacity(n + 1, vector<int>(n + 1));
	for (int i = 0; i < p; i++)
	{
		int s, e;
		cin >> s >> e;
		capacity[s][e]++;
	}
	cout << getMaxFlow(capacity, 1, 2);
	return 0;
}