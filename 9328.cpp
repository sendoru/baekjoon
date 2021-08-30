#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<int> dr = { 1, -1, 0, 0 }, dc = { 0, 0, 1, -1 };
bool isinRange(int r, int c, int rSize, int cSize)
{
	return (r >= 0 && r < rSize && c >= 0 && c < cSize);
}

/*
'.': empty
'*': wall
'$': doc
'A' ~ 'Z': door
'a' ~ 'z': key
*/

int solve(vector<string>& room, string& initKeys)
{
	int rSize = room.size(), cSize = room[0].length(), ret = 0;
	vector<vector<bool>> visited(rSize, vector<bool>(cSize, false));
	int keys = 0;
	if (initKeys[0] != '0')
	{
		for (char elem : initKeys)
		{
			keys |= (1 << (elem - 'a'));
		}
	}
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty())
	{
		int curR = q.front().first, curC = q.front().second;
		q.pop();
		if (room[curR][curC] == '$')
		{
			ret++;
		}
		else if (room[curR][curC] >= 'a' && room[curR][curC] <= 'z' && !(keys & (1 << (room[curR][curC] - 'a'))))
		{
			keys |= (1 << (room[curR][curC] - 'a'));
			visited = vector<vector<bool>>(rSize, vector<bool>(cSize, false));
			ret = 0;
			while (!q.empty())
			{
				q.pop();
			}
		}
		for (int d = 0; d < 4; d++)
		{
			int nextR = curR + dr[d], nextC = curC + dc[d];
			if (!isinRange(nextR, nextC, rSize, cSize) || visited[nextR][nextC]) continue;
			if (room[nextR][nextC] == '.' || (room[nextR][nextC] >= 'a' && room[nextR][nextC] <= 'z') || room[nextR][nextC] == '$')
			{
				q.push({ nextR, nextC });
				visited[nextR][nextC] = true;
			}
			else if ((room[nextR][nextC] >= 'A' && room[nextR][nextC] <= 'Z') && (keys & (1 << (room[nextR][nextC] - 'A'))))
			{
				q.push({ nextR, nextC });
				visited[nextR][nextC] = true;
			}
		}
	}
	return ret;
}

int main(void)
{
	int t;
	vector<int> ans;
	cin >> t;
	while (t--)
	{
		int n, m;
		string initKeys;
		cin >> n >> m;
		vector<string> room(n + 2);
		for (int i = 0; i < m + 2; i++)
		{
			room[0] += ".";
		}
		for (int i = 1; i < n + 1; i++)
		{
			cin >> room[i];
			room[i] = "." + room[i] + ".";
		}
		for (int i = 0; i < m + 2; i++)
		{
			room[n + 1] += ".";
		}
		cin >> initKeys;
		ans.push_back(solve(room, initKeys));
	}
	for (int elem : ans)
	{
		cout << elem << '\n';
	}
	return 0;
}