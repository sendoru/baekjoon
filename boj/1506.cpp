#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& s, int curNode)
{
	if (visited[curNode])
		return;
	visited[curNode] = true;
	for (auto nextNode : graph[curNode])
	{
		DFS(graph, visited, s, nextNode);
	}
	s.push(curNode);
}

void reversedDFS(vector<vector<int>>& graph, vector<bool>& visited, vector<vector<int>>& scc, int sccCnt, int curNode)
{
	if (visited[curNode])
		return;
	visited[curNode] = true;
	scc[sccCnt].push_back(curNode);
	for (auto nextNode : graph[curNode])
	{
		reversedDFS(graph, visited, scc, sccCnt, nextNode);
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> costs(n);
	vector<vector<int>> graph(n);
	vector<vector<int>> reversedGraph(n);
	vector<bool> visited(n);
	vector<bool> reversedVisited(n);
	stack<int> s;
	vector<vector<int>> scc(n);
	int sccCnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> costs[i];
	}
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == '1')
			{
				graph[i].push_back(j);
				reversedGraph[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		DFS(graph, visited, s, i);
	}
	while (!s.empty())
	{
		int curNode = s.top();
		s.pop();
		if (!reversedVisited[curNode])
		{
			reversedDFS(reversedGraph, reversedVisited, scc, sccCnt, curNode);
			sccCnt++;
		}
	}

	int ans = 0;
	for (int i = 0; i < sccCnt; i++)
	{
		int minCost = costs[scc[i][0]];
		for (auto elem : scc[i])
		{
			minCost = min(minCost, costs[elem]);
		}
		ans += minCost;
	}

	cout << ans;

	return 0;
}