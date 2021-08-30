#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int bfs(vector<string>& classroom, vector<vector<vector<vector<int>>>>& visited, pair<int, int> start, vector<pair<int, int>> p)
{
	vector<int> dr = { 1, -1, 0, 0 };
	vector<int> dc = { 0, 0, -1, 1 };
	vector<pair<int, int>> c;
	queue<vector<int>> q;
	q.push({ start.first, start.second, -1, 0, 0 });
	while(!q.empty())
	{
		int curR = q.front()[0], curC = q.front()[1], curD = q.front()[2], curDist = q.front()[3], curP = q.front()[4];
		q.pop();
		if (curP == 3)
		{
			return curDist;
		}
		for (int nextD = 0; nextD < 4; nextD++)
		{
			if (nextD == curD) continue;
			int nextR = curR + dr[nextD], nextC = curC + dc[nextD], nextP = curP;
			if (p[0].first == nextR && p[0].second == nextC)
				nextP |= 1;
			else if (p[1].first == nextR && p[1].second == nextC)
				nextP |= 2;
			if (nextR < 0 || nextR >= classroom.size() || nextC < 0 || nextC >= classroom[0].size()) continue;
			if (classroom[nextR][nextC] != '#' && visited[nextR][nextC][nextD][nextP] == -1)
			{
				visited[nextR][nextC][nextD][nextP] = curDist + 1;
				q.push({ nextR, nextC, nextD, curDist + 1, nextP });
			}
		}
	}
	return -1;

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
		int n, m;
		pair<int, int> s, c1 = { -1, -1 }, c2 = { -1, -1 };
		cin >> n >> m;
		vector<string> classroom(n);
		for (int i = 0; i < n; i++)
		{
			cin >> classroom[i];
			for (int j = 0; j < m; j++)
			{
				if (classroom[i][j] == 'S')
				{
					s.first = i;
					s.second = j;
				}
				else if (classroom[i][j] == 'C')
				{
					if (c1.first == -1)
					{
						c1.first = i;
						c1.second = j;
					}
					else
					{
						c2.first = i;
						c2.second = j;
					}
				}
			}
		}

		vector<vector<vector<vector<int>>>> visited(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(4, -1))));
		cout << bfs(classroom, visited, s, { c1, c2 }) << '\n';
	}
	return 0;
}