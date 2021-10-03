#include <iostream>
#include <vector>
#include <string>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<string> board(n);
		vector<vector<bool>> painted(n, vector<bool>(m));
		for (int i = 0; i < n; i++) cin >> board[i];

		int maxSize = 0;
		for (int rStart = 0; rStart < n; rStart++)
		{
			for (int cStart = 0; cStart < m; cStart++)
			{
				for (int d = k; d < n - rStart; d++)
				{
					vector<pair<int, int>> temp;
					bool valid = true, finished = false;
					for (int curD = 0; curD < d; curD++)
					{
						if (rStart + curD >= n || cStart + curD >= m)
						{
							valid = false;
							break;
						}
						if (board[rStart + curD][cStart + curD] == '*')
						{
							temp.push_back({ rStart + curD, cStart + curD });
						}
						else
						{
							valid = false;
							break;
						}
					}
					if (!valid) continue;


					if (rStart + d >= n || cStart + d >= m)
					{
						valid = false;
						break;
					}
					if (board[rStart + d][cStart + d] == '*')
					{
						temp.push_back({ rStart + d, cStart + d });
					}
					else
					{
						valid = false;
						break;
					}
					
					for (int curD = 1; curD <= d; curD++)
					{
						if (cStart + d + curD >= m)
						{
							valid = false;
							break;
						}
						if (board[rStart + d - curD][cStart + d + curD] == '*')
						{
							temp.push_back({ rStart + d - curD, cStart + d + curD });
						}
						else
						{
							valid = false;
							break;
						}
					}
					if (valid)
					{
						for (auto elem : temp)
						{
							painted[elem.first][elem.second] = true;
						}
					}
				}
			}
		}

		bool valid = true;
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				if ((painted[r][c] == true && board[r][c] == '.') || (painted[r][c] == false && board[r][c] == '*'))
				{
					valid = false;
					break;
				}
			}
			if (!valid) break;
		}
		cout << (valid ? "YES" : "NO") << '\n';
	}


	return 0;
}