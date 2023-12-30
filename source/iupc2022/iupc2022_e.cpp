#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int N = 20;
const ll INF = 1e9;

string toCode(string cell)
{
	if (cell[4] != '.' && cell[4] != '#') return string() + cell[4];
	if (cell == ".........") return "W";
	if (cell == "#########") return "B";
	if (cell == "#..##.###") return "UR";
	if (cell == "###.##..#") return "DL";
	if (cell == "#####.#..") return "DR";
	if (cell == "..#.#####") return "UL";
	return "";
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> board(3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> board[i];
	}
	
	vector<vector<string>> converted(n + 2, vector<string>(m + 2, "B"));
	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= m; c++)
		{
			string curStr;
			for (int i = 3 * r - 3; i < 3 * r; i++)
			{
				for (int j = 3 * c - 3; j < 3 * c; j++)
				{
					curStr.push_back(board[i][j]);
				}
			}
			converted[r][c] = toCode(curStr);
		}
	}

	bool valid = true;
	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= m; c++)
		{
			if (converted[r][c][0] >= 0 && converted[r][c][0] <= 4)
			{
				int triangleCnt = 0;
				triangleCnt += converted[r - 1][c].length() == 2;
				triangleCnt += converted[r + 1][c].length() == 2;
				triangleCnt += converted[r][c - 1].length() == 2;
				triangleCnt += converted[r][c + 1].length() == 2;
				if (triangleCnt != converted[r][c][0] - '0') valid = false;
			}
			else if (converted[r][c] == "UR")
			{
				if (!(converted[r - 1][c] == "DR"
					&& converted[r][c + 1] == "UL"
					&& (converted[r - 1][c + 1] == "DL" || converted[r - 1][c + 1] == "W")))
				{
					valid = false;
				}
			}
			else if (converted[r][c] == "UL")
			{
				if (!(converted[r - 1][c] == "DL"
					&& converted[r][c - 1] == "UR"
					&& (converted[r - 1][c - 1] == "DR" || converted[r - 1][c - 1] == "W")))
				{
					valid = false;
				}
			}
			else if (converted[r][c] == "DR")
			{
				if (!(converted[r + 1][c] == "UR"
					&& converted[r][c + 1] == "DL"
					&& (converted[r + 1][c + 1] == "UL" || converted[r + 1][c + 1] == "W")))
				{
					valid = false;
				}

			}
			else if (converted[r][c] == "DL")
			{
				if (!(converted[r + 1][c] == "UL"
					&& converted[r][c - 1] == "DR"
					&& (converted[r + 1][c - 1] == "UR" || converted[r + 1][c - 1] == "W")))
				{
					valid = false;
				}
			}
			else if (converted[r][c] == "W")
			{
				if (converted[r - 1][c] == "DR"
					&& converted[r][c + 1] == "UL"
					&& converted[r - 1][c + 1] == "DL"
					&& converted[r + 1][c] == "UL"
					&& converted[r][c - 1] == "DR"
					&& converted[r + 1][c - 1] == "UR")
				{
					continue;
				}
				else if (

					)
				{
					continue;
				}
				else if ()
				{

				}
				valid = false;
			}
		}
		if (!valid) break;
	}


	cout << (valid ? "YES" : "NO");

	return 0;
}