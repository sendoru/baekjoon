#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int bfs(vector<string>& maze, pair<int, int> start)
{
	vector<int> dr = { 1, -1, 0, 0 };
	vector<int> dc = { 0, 0, 1, -1 };
	vector<vector<vector<bool>>> visited(maze.size(), vector<vector<bool>>(maze[0].size(), vector<bool>(1 << 6)));
	visited[start.first][start.second][0] = true;
	queue<vector<int>> q;
	q.push({ start.first, start.second, 0, 0 });
	while (!q.empty())
	{
		int curR = q.front()[0], curC = q.front()[1], curKey = q.front()[2], curDist = q.front()[3];
		q.pop();
		if (maze[curR][curC] == '1')
		{
			return curDist;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextR = curR + dr[i], nextC = curC + dc[i];
			if (nextR < 0 || nextR >= maze.size() || nextC < 0 || nextC >= maze[0].size())
			{
				continue;
			}
			int nextKey = curKey;
			if (maze[nextR][nextC] >= 'a' && maze[nextR][nextC] <= 'f')
			{
				nextKey |= (1 << (maze[nextR][nextC] - 'a'));
			}
			if ((maze[nextR][nextC] == '.'
				|| maze[nextR][nextC] == '0'
				|| maze[nextR][nextC] == '1'
				|| (maze[nextR][nextC] >= 'a' && maze[nextR][nextC] <= 'f')
				|| (maze[nextR][nextC] >= 'A' && maze[nextR][nextC] <= 'F' && nextKey & (1 << (maze[nextR][nextC] - 'A'))))
				&& !visited[nextR][nextC][nextKey])
			{
				q.push({ nextR, nextC, nextKey, curDist + 1 });
				visited[nextR][nextC][nextKey] = true;
			}
		}
	}

	return -1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> maze(n);
	pair<int, int> start;
	for (int i = 0; i < n; i++)
	{
		cin >> maze[i];
		if (maze[i].find('0') != -1)
		{
			start.first = i;
			start.second = maze[i].find('0');
		}
	}

	cout << bfs(maze, start) << '\n';
	return 0;
}