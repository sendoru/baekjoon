#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int bfs(vector<string> board, set < pair<pair<int, int>, pair<int, int> > >& check, pair<int, int> red, pair<int, int> blue)
{
	vector<int> dr = { -1, 1, 0, 0 };
	vector<int> dc = { 0, 0, -1 ,1 };
	queue <pair<pair<pair<int, int>, pair<int, int> >, int> > q;
	queue < vector<string> > boardQ;
	q.push({ { red, blue }, 1 });
	boardQ.push(board);
	while (!q.empty())
	{
		pair<pair<pair<int, int>, pair<int, int> >, int> init = q.front();
		vector<string> initBoard = boardQ.front();
		check.insert(init.first);
		q.pop();
		boardQ.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> prevRed = init.first.first;
			pair<int, int> prevBlue = init.first.second;
			pair<int, int> curRed = prevRed;
			pair<int, int> curBlue = prevBlue;
			vector<string> newBoard = initBoard;
			bool flag = false;
			while (true)
			{
				// 빨간색 구슬 이동
				if (curRed.first != -1 && curRed.second != -1 && newBoard[curRed.first + dr[i]][curRed.second + dc[i]] == '.')
				{
					newBoard[curRed.first][curRed.second] = '.';
					curRed.first += dr[i];
					curRed.second += dc[i];
					newBoard[curRed.first][curRed.second] = 'R';
				}
				else if (curRed.first != -1 && curRed.second != -1 && newBoard[curRed.first + dr[i]][curRed.second + dc[i]] == 'O')
				{
					newBoard[curRed.first][curRed.second] = '.';
					curRed.first = -1;
					curRed.second = -1;
				}

				// 파란색 구슬 이동
				if (newBoard[curBlue.first + dr[i]][curBlue.second + dc[i]] == '.')
				{
					newBoard[curBlue.first][curBlue.second] = '.';
					curBlue.first += dr[i];
					curBlue.second += dc[i];
					newBoard[curBlue.first][curBlue.second] = 'B';
				}
				else if (newBoard[curBlue.first + dr[i]][curBlue.second + dc[i]] == 'O')
				{
					flag = true;
					break;
				}

				if (prevRed == curRed && prevBlue == curBlue)
				{
					break;
				}

				prevRed = curRed;
				prevBlue = curBlue;
			}

			if (!flag && curRed.first == -1 && curRed.second == -1)
			{
				return init.second;
			}

			if (!flag && check.find({ curRed, curBlue }) == check.end())
			{
				q.push({ { curRed, curBlue }, init.second + 1 });
				boardQ.push(newBoard);
			}
		}
	}

	return -1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	pair<int, int> red = { -1, -1 };
	pair<int, int> blue = { -1, -1 };
	pair<int, int> hole = { -1, -1 };
	vector<string> board(n);
	set < pair<pair<int, int>, pair<int, int> > > check;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
		{
			if (red.first == -1 && board[i][j] == 'R')
			{
				red.first = i;
				red.second = j;
			}
			else if (blue.first == -1 && board[i][j] == 'B')
			{
				blue.first = i;
				blue.second = j;
			}
			else if (hole.first == -1 && board[i][j] == 'O')
			{
				hole.first = i;
				hole.second = j;
			}
		}
	}

	cout << bfs(board, check, red, blue) << '\n';
	return 0;

}