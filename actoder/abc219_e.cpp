#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool bfs(vector<vector<int>>& adjList, int nodes)
{
	int nodeCnt = 0, visitedCnt = 0;
	queue<int> q;
	vector<bool> visited(16);

	for (int i = 0; i < 16; i++)
	{
		if (nodes & (1 << i))
		{
			if (q.empty())
			{
				q.push(i);
				visited[i] = true;
				visitedCnt++;
			}
			nodeCnt++;
		}
	}
	
	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (int nextNode : adjList[curNode])
		{
			if (!visited[nextNode] && (nodes & (1 << nextNode)))
			{
				visited[nextNode] = true;
				visitedCnt++;
				q.push(nextNode);
			}
		}
	}

	if (nodeCnt != visitedCnt)
		return false;

	for (int i = 0; i < 16; i++)
	{
		if (!visited[i])
		{
			bool valid = false;
			vector<bool> visited2 = visited;
			visited2[i] = true;
			queue<int> q2;
			q2.push(i);
			while (!q2.empty())
			{
				int curNode = q2.front();
				if (curNode != 5 && curNode != 6 && curNode != 9 && curNode != 10)
				{
					valid = true;
					break;
				}
				q2.pop();
				for (int nextNode : adjList[curNode])
				{
					if (!visited2[nextNode])
					{
						visited2[nextNode] = true;
						visitedCnt++;
						q2.push(nextNode);
					}
				}
			}

			if (!valid)
				return false;
			
		}
	}

	return true;
}

int main(void)
{
	int houses = 0;
	for (int i = 0; i < 16; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 1)
			houses += (1 << i);
	}

	vector<vector<int>> adjList(16);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// 연결된곳: 4i + j - 1, 4i + j + 1, 4i + j - 4, 4i + j + 4
			// 물론 예외처리는 해주고
			if (j != 0)
			{
				adjList[4 * i + j].push_back(4 * i + j - 1);
			}
			if (j != 3)
			{
				adjList[4 * i + j].push_back(4 * i + j + 1);
			}
			if (4 * i + j - 4 >= 0)
			{
				adjList[4 * i + j].push_back(4 * i + j - 4);
			}
			if (4 * i + j + 4 < 16)
			{
				adjList[4 * i + j].push_back(4 * i + j + 4);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << 16); i++)
	{
		if ((houses & i) != houses) continue;
		if (bfs(adjList, i)) ans++;
	}

	cout << ans;
	return 0;
}