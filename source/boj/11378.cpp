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
		for (int j = 0; j < nodeCnt; j++)
		{
			if (capacity[i][j] != 0)
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	/*
	* 1 ~ n번 노드: 직원 노드
	* n + 1 ~ m번 노드: 작업 노드
	* 0번 노드: 소스
	* n + m + 1번 노드: 소스 -> (이거) -> 직원
	* n + m + 2번 노드: 싱크
	* 그러니까 총 크기는 n + m + 3
	* 
	* 유량도 정리한다
	* 0번 -> n + m + 1번: k
	* 0번 -> 각 직원: 1
	* n + m + 1번 -> 각 직원: 무한(사실 그냥 k로 잡아도 됨)
	* 각 직원 -> 각 일: 1
	* 각 일 -> n + m + 2번: 1
	*/
	vector<vector<int>> capacity(n + m + 3, vector<int>(n + m + 3));
	capacity[0][n + m + 1] = k;
	for (int employee = 1; employee <= n; employee++)
	{
		capacity[0][employee] = 1;
		capacity[n + m + 1][employee] = k;
		int taskCnt;
		cin >> taskCnt;
		while (taskCnt--)
		{
			int task;
			cin >> task;
			task += n;
			capacity[employee][task] = 1;
		}
	}
	for (int task = n + 1; task <= n + m; task++)
	{
		capacity[task][n + m + 2] = 1;
	}
	cout << getMaxFlow(capacity, 0, n + m + 2);
	return 0;
}