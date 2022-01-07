#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> solve(vector<vector<pair<int, int>>>& graph, vector<int>& preCnt, int s, int e)
{
	// criticalRoute[i] := first는 최대 cost, second는 critical route에 포함된 이전 정점
	vector<pair<int, vector<int>>> criticalRoute(graph.size());
	vector<int> tpSortOrder;
	queue<int> q;
	q.push(s);
	criticalRoute[s] = { 0, {} };


	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (auto curEdge : graph[curNode])
		{
			int nextNode = curEdge.first;
			int nextCost = curEdge.second;
			if (criticalRoute[nextNode].first < criticalRoute[curNode].first + nextCost)
			{
				criticalRoute[nextNode].first = criticalRoute[curNode].first + nextCost;
				criticalRoute[nextNode].second = { curNode };
			}
			else if (criticalRoute[nextNode].first == criticalRoute[curNode].first + nextCost)
			{
				criticalRoute[nextNode].second.push_back(curNode);
			}

			preCnt[nextNode]--;
			if (preCnt[nextNode] == 0)
			{
				q.push(nextNode);
			}
		}
	}
	
	// 반대 방향으로 위상 정렬
	int criticalEdgeCnt = 0;
	vector<int> reversedPreCnt(graph.size());
	for (int i = 1; i < graph.size(); i++)
	{
		for (auto nextNode: criticalRoute[i].second)
		{
			reversedPreCnt[nextNode]++;
		}
	}
	set<pair<int, int>> criticalEdge;
	q.push(e);
	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (auto& nextNode : criticalRoute[curNode].second)
		{
			if (nextNode != -1)
			{
				criticalEdgeCnt++;
				reversedPreCnt[nextNode]--;
				q.push(nextNode);
				nextNode = -1;
			}
		}
	}

	return { criticalRoute[e].first, criticalEdgeCnt };
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1), reversedGraph(n + 1);
	vector<int> preCnt(n + 1);
	for (int i = 0; i < m; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		graph[s].push_back({ e, cost });
		preCnt[e]++;
	}
	int s, e;
	cin >> s >> e;
	auto ans = solve(graph, preCnt, s, e);
	cout << ans.first << '\n' << ans.second;
	return 0;
}