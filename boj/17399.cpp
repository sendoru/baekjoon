#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100010

using namespace std;
typedef long long ll;

void dfs(vector<vector<int>>& graph, vector<int>& parents, vector<int>& depths, int curNode, int curDepth)
{
	depths[curNode] = curDepth;
	for (int nextNode : graph[curNode])
	{
		if (depths[nextNode] == -1)
		{
			parents[nextNode] = curNode;
			dfs(graph, parents, depths, nextNode, curDepth + 1);
		}
	}
}

void makeSparseTable(vector<vector<int>>& sparseTable, vector<int>& parents)
{
	for (int i = 0; i < parents.size(); i++)
	{
		sparseTable[0][i] = parents[i];
	}
	for (int i = 1; i < sparseTable.size(); i++)
	{
		for (int j = 0; j < sparseTable[i].size(); j++)
		{
			sparseTable[i][j] = sparseTable[i - 1][sparseTable[i - 1][j]];
		}
	}
}

int getLCA(vector<vector<int>>& sparseTable, vector<int>& depths, int u, int v)
{
	if (depths[u] < depths[v])
		swap(u, v);
	int depthDiff = depths[u] - depths[v];
	for (int i = sparseTable.size() - 1; i >= 0; i--)
	{
		if (depthDiff & (1 << i))
		{
			u = sparseTable[i][u];
		}
	}
	if (u == v)
	{
		return v;
	}
	for (int i = sparseTable.size() - 1; i >= 0; i--)
	{
		if (sparseTable[i][u] != sparseTable[i][v])
		{
			u = sparseTable[i][u];
			v = sparseTable[i][v];
		}
	}
	return sparseTable[0][v];
}

int getNthParent(vector<vector<int>>& sparseTable, int v, int n)
{
	for (int i = sparseTable.size() - 1; i >= 0; i--)
	{
		if (n & (1 << i))
		{
			v = sparseTable[i][v];
		}
	}
	return v;
}

int getDist(vector<vector<int>>& sparseTable, vector<int>& depths, int u, int v)
{
	int lca = getLCA(sparseTable, depths, u, v);
	int dist = (depths[u] + depths[v]) - 2 * depths[lca];
	return dist;
}

int getMiddlePoint(vector<vector<int>>& sparseTable, vector<int>& depths, int u, int v)
{
	if ((depths[u] + depths[v]) & 1)
		return -1;

	int lca = getLCA(sparseTable, depths, u, v);
	int dist = (depths[u] + depths[v]) / 2 - depths[lca];

	if (depths[u] == depths[v])
		return lca;
	else if (depths[u] > depths[v])
		return getNthParent(sparseTable, u, dist);
	else
		return getNthParent(sparseTable, v, dist);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1);
	vector<int> parents(n + 1);
	vector<vector<int>> sparseTable(18, vector<int>(n + 1));
	vector<int> depths(n + 1, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(graph, parents, depths, 1, 0);
	parents[1] = 1;
	makeSparseTable(sparseTable, parents);
	
	int q;
	cin >> q;
	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		// 일단 세 정점 중에 같은 정점이 있는 경우는 예외처리
		if (a == b && b == c && c == a)
		{
			cout << a << '\n';
			continue;
		}

		// 일단 a-b의 중점(abMid)부터 구한다. 없으면 -1
		int abLCA = getLCA(sparseTable, depths, a, b),
			abDist = getDist(sparseTable, depths, a, b),
			abMid = getMiddlePoint(sparseTable, depths, a, b);
		if (abMid == -1)
		{
			cout << -1 << '\n';
			continue;
		}

		// 그리고 c와 a-b의 중점 사이의 거리를 구한다.
		int cMidLCA = getLCA(sparseTable, depths, abMid, c);
		int cMidDist = (depths[abMid] + depths[c]) - 2 * depths[cMidLCA];
		// a-abMid, b-abMid, c-abMid 거리가 전부 같으면 abMid가 정답
		if (cMidDist * 2 == abDist)
		{
			cout << abMid << '\n';
			continue;
		}

		// a-abMid, b-abMid 거리가 c-abMid 거리보다 길면 -1
		else if (cMidDist * 2 < abDist)
		{
			cout << -1 << '\n';
			continue;
		}

		// 이제 a-b를 잇는 경로와 abMid-c를 잇는 경로 중에 겹치는 간선이 있는지 봐야 된다.
		// 겹치는 간선이 있으면 -1
		else
		{
			int diff = cMidDist - abDist / 2;
			if (diff & 1)
			{
				cout << -1 << '\n';
				continue;
			}
			diff /= 2;
			if (a != b)
			{
				// a-b를 잇는 경로에서 abMid 양 옆의 정점을 구하는 노가다
				// abMid에서 옆 점으로 갔을 때 abMid와 C 사이의 거리가 줄어들면 abMid-c 경로와 a-b 경로가 겹치는거임
				int abMidtoA, abMidtoB;
				if (depths[a] == depths[b])
				{
					abMidtoA = getNthParent(sparseTable, a, depths[a] - depths[abMid] - 1);
					abMidtoB = getNthParent(sparseTable, b, depths[b] - depths[abMid] - 1);
				}
				else if (depths[a] < depths[b])
				{
					abMidtoA = parents[abMid];
					abMidtoB = getNthParent(sparseTable, b, depths[b] - depths[abMid] - 1);
				}
				else
				{
					abMidtoA = getNthParent(sparseTable, a, depths[a] - depths[abMid] - 1);
					abMidtoB = parents[abMid];
				}
				// 겹치는 간선이 있는 경우
				if (getDist(sparseTable, depths, abMidtoA, c) < cMidDist || getDist(sparseTable, depths, abMidtoB, c) < cMidDist)
				{
					cout << -1 << '\n';
					continue;
				}
			}

			int ans;
			if (diff <= depths[abMid] - depths[cMidLCA])
			{
				ans = getNthParent(sparseTable, abMid, diff);
			}
			else
			{
				diff -= depths[abMid] - depths[cMidLCA];
				ans = getNthParent(sparseTable, c, depths[c] - depths[cMidLCA] - diff);
			}
			cout << ans << '\n';
		}
	}

	return 0;
}