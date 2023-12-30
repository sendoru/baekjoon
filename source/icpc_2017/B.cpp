#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <random>
#define DEBUG
#undef DEBUG
using namespace std;
typedef long long ll;
constexpr ll INF = 2e9;
constexpr ll MOD = 1e9 + 7;

char check(vector<vector<char>>& board)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			// 세로 
			if (board[i][j] == 'B' && board[i][j + 1] == 'B' && board[i][j + 2] == 'B')
			{
				return 'B';
			}
			else if (board[i][j] == 'W' && board[i][j + 1] == 'W' && board[i][j + 2] == 'W')
			{
				return 'W';
			}
			else if (board[j][i] == 'B' && board[j + 1][i] == 'B' && board[j + 2][i] == 'B')
			{
				return 'B';
			}
			else if (board[j][i] == 'W' && board[j + 1][i] == 'W' && board[j + 2][i] == 'W')
			{
				return 'W';
			}
			// 가로
		}
	}

	for (char c : vector<char>('B', 'W'))
	{
		if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
		{
			return c;
		}
		if (board[0][1] == c && board[1][2] == c && board[2][3] == c)
		{
			return c;
		}
		if (board[1][0] == c && board[2][1] == c && board[3][2] == c)
		{
			return c;
		}
		if (board[1][1] == c && board[2][2] == c && board[3][3] == c)
		{
			return c;
		}
	}
	return 'X';
}

ll solve(int n, int r, int c)
{
	// BFS?
	pair<vector<int>, vector<vector<char>>> s =
	{
		vector<int>({0, 0, 0, 0}),
		{
			{'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X'},
		}
	};

	s.second[n][0] = 'B';
	s.first[n]++;

	set<pair<vector<int>, vector<vector<char>>>> visited;
	queue<pair<vector<int>, vector<vector<char>>>> q;
	q.push(s);

	ll ans = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		if (check(cur.second) != 'X')
			continue;

		if (cur == s)
		{
			visited.insert(cur);
		}

		for (int i = 0; i < 4; i++)
		{
			if (cur.first[i] == 4)
			{
				continue;
			}
			pair<int, int> nextPos = { i, cur.first[i] };
			auto nextNode = cur;

			int isOdd = 0;
			for (int j = 0; j < 4; j++)
			{
				isOdd += cur.first[j];
				isOdd &= 1;
			}

			// isOdd == 1이면 흰색, 아니면 검은색을 넣어야 됨
			if (isOdd)
			{
				nextNode.second[i][nextNode.first[i]] = 'W';
				nextNode.first[i]++;
				if (visited.find(nextNode) == visited.end())
				{
					if (i == r && nextNode.first[i] == c + 1 && check(nextNode.second) == 'W')
					{
						ans++;
					}
					visited.insert(nextNode);
					q.push(nextNode);
				}
			}
			else
			{
				nextNode.second[i][nextNode.first[i]] = 'B';
				nextNode.first[i]++;
				if (visited.find(nextNode) == visited.end())
				{
					visited.insert(nextNode);
					q.push(nextNode);
				}
			}
		}
	}

	return ans;
}

int main(void)
{
	int n;
	cin >> n;
	int r, c;
	cin >> r >> c;
	n--;
	r--;
	c--;

	swap(r, c);

	cout << solve(n, r, c);
	return 0;
}