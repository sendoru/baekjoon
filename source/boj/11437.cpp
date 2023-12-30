#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50001

using namespace std;

vector<vector<int>> graph(MAX);
int parent[MAX];
int depth[MAX];

void dfs(int parentNode, int currentDepth)
{
	currentDepth++;
	depth[parentNode] = currentDepth;
	for (int nextNode : graph[parentNode])
	{
		if (depth[nextNode] == 0)
		{
			parent[nextNode] = parentNode;
			dfs(nextNode, currentDepth);
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int countofNodes;
	cin >> countofNodes;
	for (int i = 0; i < countofNodes - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 1);

	int countofPairs;
	cin >> countofPairs;

	for (int i = 0; i < countofPairs; i++)
	{
		int a, b;
		cin >> a >> b;
		if (depth[a] > depth[b])
		{
			swap(a, b);
		}
		while (depth[a] != depth[b])
		{
			b = parent[b];
		}
		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}
		cout << a << '\n';
	}

	return 0;
}