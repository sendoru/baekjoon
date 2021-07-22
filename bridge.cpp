#include <iostream>
#include <vector>

using namespace std;

int findCutVertex(vector<vector<int>>& graph, vector<int>& visited, vector<bool>& isCutVertex, int& vertexCnt, int root, int curVertex)
{
	visited[curVertex] = ++vertexCnt;
	int ret = visited[curVertex];
	int childrenCnt = 0;
	for (int nextVertex : graph[curVertex])
	{
		if (!visited[nextVertex])
		{
			childrenCnt++;
			int subtree = findCutVertex(graph, visited, isCutVertex, vertexCnt, root, nextVertex);
			if (curVertex != root && subtree >= visited[curVertex])
			{
				isCutVertex[curVertex] = true;
			}
			ret = min(ret, subtree);
		}
		else
		{
			ret = min(ret, visited[nextVertex]);
		}
	}
	if (curVertex == root)
	{
		isCutVertex[curVertex] = (childrenCnt >= 2);
	}
	return ret;
}

int main(void)
{
	int v, e;
	cin >> v >> e;
	vector<vector<int>> graph(v);
	vector<int> visited(v);
	vector<bool> isCutVertex(v);
	int vertexCnt = 0, cutVertexCnt = 0;
	for (int i = 0; i < e; i++)
	{
		int start, end;
		cin >> start >> end;
		start--; end--;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 0; i < v; i++)
	{
		if (visited[i] == -1)
		{
			findCutVertex(graph, visited, isCutVertex, vertexCnt, i, i);
		}
	}
	for (bool vertex : isCutVertex)
	{
		cutVertexCnt += vertex;
	}
	cout << cutVertexCnt << '\n';
	for (int i = 0; i < isCutVertex.size(); i++)
	{
		if (isCutVertex[i])
		{
			cout << i + 1 << ' ';
		}
	}

	return 0;
}