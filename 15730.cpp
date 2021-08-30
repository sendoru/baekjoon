#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

pair<int, int> bfs(vector<vector<int>>& pool, vector<vector<int>>& visited, vector<vector<int>>& maximum, int r, int c, int h)
{
	vector<vector<int>> copiedVisited = visited;
	int ret = 0, maxH = 0;
	vector<int> dr = { 1, -1, 0, 0 };
	vector<int> dc = { 0, 0, 1, -1 };
	queue<pair<int, int>> q;
	q.push({ r, c });
	copiedVisited[r][c] = h;
	while (!q.empty())
	{
		pair<int, int> curNode = q.front();
		q.pop();
		if (curNode.first == 0 || curNode.first == pool.size() - 1 || curNode.second == 0 || curNode.second == pool[0].size() - 1)
		{
			return { -1, max(maxH, pool[curNode.first][curNode.second]) };
		}
		ret += h - pool[curNode.first][curNode.second];
		maxH = max(maxH, pool[curNode.first][curNode.second]);
		for (int d = 0; d < 4; d++)
		{
			if (copiedVisited[curNode.first + dr[d]][curNode.second + dc[d]] != 0 && copiedVisited[curNode.first + dr[d]][curNode.second + dc[d]] < h)
			{
				return { -1, max(maxH, copiedVisited[curNode.first + dr[d]][curNode.second + dc[d]]) };
			}
			if (copiedVisited[curNode.first + dr[d]][curNode.second + dc[d]] == 0 && pool[curNode.first + dr[d]][curNode.second + dc[d]] < h)
			{
				copiedVisited[curNode.first + dr[d]][curNode.second + dc[d]] = h;
				maximum[curNode.first + dr[d]][curNode.second + dc[d]] = min(maximum[curNode.first + dr[d]][curNode.second + dc[d]], h);
				q.push({ curNode.first + dr[d], curNode.second + dc[d] });
			}
		}
	}
	visited = copiedVisited;
	return { ret, 0 };
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// int t;
	// cin >> t;
	// while (t--)
	{
		int n, m, highest = 0;
		cin >> n >> m;
		vector<vector<int>> pool(n, vector<int>(m));
		vector<vector<int>> visited(n, vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> pool[i][j];
				highest = max(highest, pool[i][j]);
			}
		}
		vector<vector<int>> maximum(n, vector<int>(m, highest));

		int ans = 0;
		pair<int ,int> BFSret;

		for (int r = 1; r < n - 1; r++)
		{
			for (int c = 1; c < m - 1; c++)
			{
				if (visited[r][c])
				{
					continue;
				}
				for (int h = maximum[r][c]; h > pool[r][c]; h--)
				{
					BFSret = bfs(pool, visited, maximum, r, c, h);
					if (BFSret.first > 0)
					{
						ans += BFSret.first;
						break;
					}
					else
						h = min(h, BFSret.second + 1);
				}
			}
		}


		cout << ans << '\n';
	}

	return 0;
}

