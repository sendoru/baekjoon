#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

int main(void)
{
	int n, x, y;
	cin >> n >> x >> y;
	vector<pair<int, int>> ab(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> ab[i].first >> ab[i].second;
	}

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(x + 1, vector<int>(y + 1, INF)));
	for (int i = 0; i <= n; i++)
	{
		if (i == 0) dp[0][0][0] = 0;
		else
		{
			for (int j = 0; j <= x; j++)
			{
				for (int k = 0; k <= y; k++)
				{
					dp[i][min(x, j + ab[i].first)][min(y, k + ab[i].second)] = min(dp[i][min(x, j + ab[i].first)][min(y, k + ab[i].second)], dp[i - 1][j][k] + 1);
				}
			}
			for (int j = 0; j <= x; j++)
			{
				for (int k = 0; k <= y; k++)
				{
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
				}
			}
			
		}
	}

	cout << (dp[n][x][y] >= INF ? -1 : dp[n][x][y]);
	return 0;
}