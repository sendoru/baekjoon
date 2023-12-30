#include <iostream>
#include <vector>
using namespace std;

int DR[4] = { 1, -1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };

bool solve(pair<int, int> curLoc, pair<int, int> destination, vector<vector<int>>& visitOrder, int visitCnt)
{
	if (curLoc == destination)
	{
		if (visitCnt == visitOrder.size() * visitOrder[0].size() - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nextR = curLoc.first + DR[i], nextC = curLoc.second + DC[i];
			if (nextR >= 0 && nextR < visitOrder.size() && nextC >= 0 && nextC < visitOrder[0].size() && visitOrder[nextR][nextC] == -1)
			{
				visitOrder[nextR][nextC] = visitCnt + 1;
				bool solved = solve({ nextR, nextC }, destination, visitOrder, visitCnt + 1);
				if (solved)
				{
					return true;
				}
				visitOrder[nextR][nextC] = -1;
			}
		}
		return false;
	}
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
		int m, n, r1, c1, r2, c2;
		cin >> m >> n >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		vector<vector<int>> visitOrder(m, vector<int>(n, -1));
		visitOrder[r1][c1] = 0;
		if ((abs(r1 - r2) + abs(c1 - c2)) % 2 == 0)
		{
			cout << -1 << '\n';
			continue;
		}
		bool solved = solve({ r1, c1 }, { r2, c2 }, visitOrder, 0);
		if (!solved)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << 1 << '\n';
			vector<pair<int, int>> locs(m * n);
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					locs[visitOrder[i][j]] = { i + 1, j + 1 };
				}
			}
			for (auto elem : locs)
			{
				cout << elem.first << ' ' << elem.second << '\n';
			}
		}
	}
}