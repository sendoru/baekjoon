#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

bool verdict(vector<vector<int>>& board)
{
	vector<pair<int, int>> moves =
	{
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};
	for (int i = 1; i < board.size() - 1; i++)
	{
		for (int j = 1; j < board.size() - 1; j++)
		{
			int gt = 0, ls = 0;
			for (auto move : moves)
			{
				if (board[i + move.first][j + move.second] == board[i][j])
				{
					return false;
				}
				else if (board[i + move.first][j + move.second] > board[i][j])
				{
					gt++;
				}
				else
				{
					ls++;
				}
			}

			if (gt == ls)
			{
				return false;
			}
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	int curNum = 1;
	int curDiag = 0;
	int diagSize = 1;
	vector<vector<int>> ans(n, vector<int>(n, -1));
	for (curDiag; curDiag < 2 * n; curDiag++)
	{
		int r = curDiag, c = 0;
		while (r >= n)
		{
			r--;
			c++;
		}
		while (r >= 0 && c < n)
		{
			ans[r][c] = curNum;
			curNum++;
			r--;
			c++;
		}

		r = curDiag, c = 0;
		while (r >= n)
		{
			r--;
			c++;
		}

		while (r - 1 >= 0 && c + 1 < n)
		{
			swap(ans[r][c], ans[r - 1][c + 1]);
			r -= 2;
			c += 2;
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	// cout << (verdict(ans) ? "OK" : "NO") << '\n';

	return 0;
}