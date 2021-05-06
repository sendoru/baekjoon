#include <iostream>
#include <vector>

using namespace std;

int dfs(int y, int x, vector<vector<int> >& map, vector<vector<int> >& dp, int ySize, int xSize)
{
	if (y == ySize - 1 && x == xSize - 1)
	{
		dp[y][x] = 1;
		return 1;
	}

	if (dp[y][x] != -1)
	{
		return dp[y][x];
	}

	dp[y][x] = 0;

	if (y > 0 && map[y - 1][x] < map[y][x])
	{
		dp[y][x] += dfs(y - 1, x, map, dp, ySize, xSize);
	}
	if (y < ySize - 1 && map[y + 1][x] < map[y][x])
	{
		dp[y][x] += dfs(y + 1, x, map, dp, ySize, xSize);
	}
	if (x > 0 && map[y][x - 1] < map[y][x])
	{
		dp[y][x] += dfs(y, x - 1, map, dp, ySize, xSize);
	}
	if (x < xSize - 1 && map[y][x + 1] < map[y][x])
	{
		dp[y][x] += dfs(y, x + 1, map, dp, ySize, xSize);
	}

	return dp[y][x];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int> > map(n, vector<int>(m));
	vector<vector<int> > dp(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0, map, dp, n, m) << '\n';
	
	return 0;
}