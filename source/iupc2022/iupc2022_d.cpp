#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int N = 20;

// U: 위, D: 아래, F: 앞, B: 뒤, R: 오, L: 왼

int solve(vector<string>& board)
{
	// 아래, 위, 오른, 왼
	vector<int> dr = { 1, -1, 0, 0 };
	vector<int> dc = { 0, 0, 1, -1 };

	map<char, vector<char>> nextDirs =
	{
		{'U', {'F', 'B', 'R', 'L'}},
		{'D', {'B', 'F', 'L', 'R'}},
		{'F', {'D', 'U', 'F', 'F'}},
		{'B', {'U', 'D', 'B', 'B'}},
		{'R', {'R', 'R', 'D', 'U'}},
		{'L', {'L', 'L', 'U', 'D'}},
	};

	map<char, int> dirCharToInt = 
	{
		{'U', 0},
		{'D', 1},
		{'F', 2},
		{'B', 3},
		{'R', 4},
		{'L', 5},
	};

	vector<char> dirIntToChar = { 'U', 'D', 'F', 'B', 'R', 'L' };


	pair<int, int> startPos = { -1,-1 };
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] == 'D')
				startPos = { i, j };

	queue<pair<pair<int, int>, char>> q;
	vector<vector<vector<int>>> dist(board.size(), vector<vector<int>>(board[0].size(), {-1, -1, -1, -1, -1, -1}));
	q.push({ startPos, 'D' });
	dist[startPos.first][startPos.second][1] = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int curR = cur.first.first;
		int curC = cur.first.second;
		char curDir = cur.second;

		if (board[curR][curC] == 'R' && curDir == 'D')
		{
			return dist[curR][curC][1];
		}

		for (int i = 0; i < 4; i++)
		{
			int nextR = curR + dr[i];
			int nextC = curC + dc[i];
			int nextDir = nextDirs[curDir][i];

			if (nextR >= 0 && nextR < board.size() && nextC >= 0 && nextC < board[0].size() &&
				board[nextR][nextC] != '#' && !(board[nextR][nextC] == 'R' && nextDir != 'D') && dist[nextR][nextC][dirCharToInt[nextDir]] == -1)
			{
				dist[nextR][nextC][dirCharToInt[nextDir]] = dist[curR][curC][dirCharToInt[curDir]] + 1;
				q.push({ make_pair(nextR, nextC), nextDir });
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

	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	cout << solve(board);
	return 0;
}