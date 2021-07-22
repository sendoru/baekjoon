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
	while (true)
	{
		int v, e;
		cin >> v;
		if (v == 0)
			break;
		cin >> e;
		vector<set<int>> graph(v);
		vector<set<int>> reversedGraph(v);
		vector<set<int>> scc(v);
		vector<int> sccNo(v);
		vector<bool> visited(v);
		vector<bool> reversedVisited(v);
		vector<bool> sccVisited(v);
		stack<int> s;
		vector<bool> scchasChild (v);
		set<int> bottom;
		int root = -1, sccCnt = 0;
		bool confused = false;

		for (int i = 0; i < e; i++)
		{
			int start, end;
			cin >> start >> end;
			start--; end--;
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
		scchasChild .resize(sccCnt);
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
			if (!scchasChild[sccNo[i]])
			{
				for (auto elem : graph[i])
				{
					if (scc[sccNo[i]].find(elem) == scc[sccNo[i]].end())
					{
						scchasChild[sccNo[i]] = true;
						break;
					}
				}
			}
		}

		for (int i = 0; i < scc.size(); i++)
		{
			if (!scchasChild[i])
			{
				for (auto elem : scc[i])
				{
					bottom.insert(elem);
				}
			}
		}

		for (auto elem : bottom)
		{
			cout << elem + 1 << ' ';
		}

		cout << '\n';
	}

	return 0;
}