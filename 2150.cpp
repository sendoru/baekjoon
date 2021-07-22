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
	vector<vector<int>> graph(n);
	vector<int> visited(n, -1);
	vector<int> discovered(n);
	vector<set<int>> scc(n);
	vector<int> sccNo(n, -1);
	stack<int> s;
	int sccCnt = 0, nodeCnt = 0;
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		start--; end--;
		graph[start].push_back(end);
	}

	for (int i = 0; i < graph.size(); i++)
	{
		if (visited[i] == -1)
		{
			dfs(graph, visited, sccNo, s, sccCnt, nodeCnt, i);
		}
	}

	for (int i = 0; i < sccNo.size(); i++)
	{
		scc[sccNo[i]].insert(i);
	}

	scc.resize(sccCnt);

	cout << sccCnt << '\n';
	sort(scc.begin(), scc.end());
	for (auto curScc : scc)
	{
		for (auto curNode : curScc)
		{
			cout << curNode << ' ';
		}
		cout << '\n';
	}



	return 0;

}