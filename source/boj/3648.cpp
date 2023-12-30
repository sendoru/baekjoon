#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int sgn(int n)
{
	if (n > 0)
		return 1;
	if (n == 0)
		return 0;
	return -1;
}

int abs(int n)
{
	return n * sgn(n);
}

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
	while (true)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m;
		cin >> n;
		if (cin.eof())
		{
			break;
		}
		cin >> m;
		// A : 2 * A번에 할당
		// not A : 2 * A + 1번에 할당
		vector<vector<int>> graph(2 * n + 2);
		vector<vector<int>> reversedGraph(2 * n + 2);
		vector<bool> visited(2 * n + 2);
		vector<bool> reversedVisited(2 * n + 2);
		vector<vector<int>> scc(2 * n + 2);
		vector<int> sccNo(2 * n + 2);
		stack<int> s;
		int sccCnt = 0;
		for (int i = 0; i < m; i++)
		{
			int start, end, notStart, notEnd;
			cin >> start >> end;
			if (start > 0)
			{
				start *= 2;
				notStart = start + 1;
			}
			else
			{
				start = -2 * start + 1;
				notStart = start - 1;
			}
			if (end > 0)
			{
				end *= 2;
				notEnd = end + 1;
			}
			else
			{
				end = -2 * end + 1;
				notEnd = end - 1;
			}
			graph[notStart].push_back(end);
			graph[notEnd].push_back(start);
			reversedGraph[end].push_back(notStart);
			reversedGraph[start].push_back(notEnd);
		}
		graph[3].push_back(2);
		reversedGraph[2].push_back(3);

		for (int i = 2; i < graph.size(); i++)
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

		for (int i = 0; i < sccCnt; i++)
		{
			for (auto elem : scc[i])
			{
				sccNo[elem] = i;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (sccNo[i * 2] == sccNo[i * 2 + 1])
			{
				cout << "no" << '\n';
				break;
			}
			if (i == n)
			{
				cout << "yes" << '\n';
			}
		}
	}
	return 0;

}