#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& sccNo, stack<int>& s, int& sccCnt, int& nodeCnt, int curNode)
{
	int ret = visited[curNode] = nodeCnt++;
	s.push(curNode);
	for (auto nextNode : graph[curNode])
	{
		if (visited[nextNode] == -1)
			ret = min(ret, dfs(graph, visited, sccNo, s, sccCnt, nodeCnt, nextNode));
		else if (sccNo[nextNode] == -1)
			ret = min(ret, visited[nextNode]);
	}
	if (ret == visited[curNode])
	{
		while (true)
		{
			int t = s.top();
			s.pop();
			sccNo[t] = sccCnt;
			if (t == curNode)
				break;
		}
		sccCnt++;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	// A : 2 * A번에 할당
	// not A : 2 * A + 1번에 할당
	vector<vector<int>> graph(2 * n + 2);
	vector<int> visited(2 * n + 2, -1);
	vector<set<int>> scc(2 * n + 2);
	vector<int> sccNo(2 * n + 2);
	stack<int> s;
	int sccCnt = 0, nodeCnt = 0;
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
	}

	for (int i = 2; i < graph.size(); i++)
	{
		if (visited[i] == -1)
		{
			dfs(graph, visited, sccNo, s, sccCnt, nodeCnt, i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (sccNo[i * 2] == sccNo[i * 2 + 1])
		{
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	for (int i = 1; i <= n; i++)
	{
		int output = sccNo[2 * i] > sccNo[2 * i + 1];
		cout << output << ' ';
	}

	return 0;

}