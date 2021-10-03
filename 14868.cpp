#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

pair<int, int> findRoot(pair<int, int> x, vector<vector<pair<int, int>>>& roots)
{
	if (roots[x.first][x.second] == x) return x;
	return roots[x.first][x.second] = findRoot(roots[x.first][x.second], roots);
}

bool hasSameRoots(pair<int, int> x, pair<int, int> y, vector<vector<pair<int, int>>>& roots)
{
	return (findRoot(x, roots) == findRoot(y, roots));
}

void unite(pair<int, int> x, pair<int, int> y, vector<vector<pair<int, int>>>& roots, vector<vector<int>>& sizes)
{
	pair<int, int> xRoot = findRoot(x, roots), yRoot = findRoot(y, roots);
	if (xRoot != yRoot)
	{
		sizes[xRoot.first][xRoot.second] += sizes[yRoot.first][yRoot.second];
		roots[yRoot.first][yRoot.second] = xRoot;
	}
}

int getSize(pair<int, int> x, vector<vector<pair<int, int>>>& roots, vector<vector<int>>& sizes)
{
	pair<int, int> xRoot = findRoot(x, roots);
	return sizes[roots[xRoot.first][xRoot.second].first][roots[xRoot.first][xRoot.second].second];
}

int bfs(vector<vector<int>>& world)
{
	int ret = 0, n = world.size(), visitedCnt = 0;
	vector<int> dr = { 1, -1, 0, 0 };
	vector<int> dc = { 0, 0, -1, 1 };
	queue<pair<pair<int, int>, int>> q;
	vector<vector<pair<int, int>>> roots(n, vector<pair<int, int>>(n));
	vector<vector<bool>> visited(n, vector<bool>(n));
	vector<vector<int>> sizes(n, vector<int>(n, 1));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			roots[i][j] = make_pair(i, j);
			if (world[i][j] == 0)
			{
				q.push(make_pair(make_pair(i, j), 0));
				visited[i][j] = true;
				visitedCnt++;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> curNode = q.front().first;
		int timeCnt = q.front().second;
		world[curNode.first][curNode.second] = timeCnt;
		if (timeCnt != 0) visitedCnt++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (curNode.first + dr[i] >= 0 && curNode.first + dr[i] < n && curNode.second + dc[i] >= 0 && curNode.second + dc[i] < n
				&& world[curNode.first + dr[i]][curNode.second + dc[i]] != -1)
			{
				unite({ curNode.first, curNode.second }, { curNode.first + dr[i], curNode.second + dc[i] }, roots, sizes);
			}
		}

		if (visitedCnt == getSize(curNode, roots, sizes)) return timeCnt;

		for (int i = 0; i < 4; i++)
		{
			if (curNode.first + dr[i] >= 0 && curNode.first + dr[i] < n && curNode.second + dc[i] >= 0 && curNode.second + dc[i] < n
				&& !visited[curNode.first + dr[i]][curNode.second + dc[i]])
			{
				
				visited[curNode.first + dr[i]][curNode.second + dc[i]] = true;
				q.push({ {curNode.first + dr[i], curNode.second + dc[i]}, timeCnt + 1});
			}
		}
	}

	return INF;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> world(n, vector<int>(n, -1));
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		world[a][b] = 0;
	}
	cout << bfs(world);
	return 0;

}