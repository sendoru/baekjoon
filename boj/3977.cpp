#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(vector<set<int>>& graph, vector<bool>& visited, stack<int>& s, int curNode)
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

void reversedDFS(vector<set<int>>& graph, vector<bool>& visited, vector<set<int>>& scc, int sccCnt, int curNode)
{
	if (visited[curNode])
		return;
	visited[curNode] = true;
	scc[sccCnt].insert(curNode);
	for (auto nextNode : graph[curNode])
	{
		reversedDFS(graph, visited, scc, sccCnt, nextNode);
	}
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
		int v, e;
		cin >> v >> e;
		vector<set<int>> graph(v);
		vector<set<int>> reversedGraph(v);
		vector<set<int>> scc(v);
		vector<int> sccNo(v);
		vector<bool> visited(v);
		vector<bool> reversedVisited(v);
		vector<bool> sccVisited(v);
		stack<int> s;
		vector<set<int>> pre(v);
		vector<bool> suc(v, -1);
		vector<bool> scchasParent(v);
		int root = -1, sccCnt = 0;
		bool confused = false;

		for (int i = 0; i < e; i++)
		{
			int start, end;
			cin >> start >> end;
			graph[start].insert(end);
			reversedGraph[end].insert(start);
		}

		for (int i = 0; i < v; i++)
		{
			if (!visited[i])
			{
				DFS(graph, visited, s, i);
			}
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

		scc.resize(sccCnt);
		sccVisited.resize(sccCnt);
		scchasParent.resize(sccCnt);
		// O(v)
		for (int i = 0; i < sccCnt; i++)
		{
			auto elem = scc[i];
			for (auto vertex : elem)
			{
				sccNo[vertex] = i;
			}
		}

		// O(e*loge)
		for (int i = 0; i < v; i++)
		{
			if (!scchasParent[sccNo[i]])
			{
				for (auto elem : reversedGraph[i])
				{
					if (scc[sccNo[i]].find(elem) == scc[sccNo[i]].end())
					{
						scchasParent[sccNo[i]] = true;
						break;
					}
				}
			}
		}

		for (int i = 0; i < scchasParent.size(); i++)
		{
			if (!scchasParent[i])
			{
				if (root == -1)
				{
					root = i;
				}
				else
				{
					confused = true;
					break;
				}
			}
		}

		if (confused)
		{
			cout << "Confused" << '\n';
		}
		else
		{
			for (auto elem : scc[root])
			{
				cout << elem << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}