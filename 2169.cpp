#include <iostream>
#include <vector>

using namespace std;
const int MIN = 0xa0000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> value(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m, MIN));
	vector<vector<int>> dpFromLeft(n, vector<int>(m, MIN));
	vector<vector<int>> dpFromRight(n, vector<int>(m, MIN));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> value[i][j];
		}
	}
	dp[0][0] = value[0][0];
	for (int i = 1; i < m; i++)
	{
		dp[0][i] = dp[0][i - 1] + value[0][i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				dpFromLeft[i][j] = dp[i - 1][j] + value[i][j];
			}
			else
			{
				dpFromLeft[i][j] = max(dp[i - 1][j], dpFromLeft[i][j - 1]) + value[i][j];
			}
		}
		for (int j = m - 1; j >= 0; j--)
		{
			if (j == m - 1)
			{
				dpFromRight[i][j] = dp[i - 1][j] + value[i][j];
			}
			else
			{
				dpFromRight[i][j] = max(dp[i - 1][j], dpFromRight[i][j + 1]) + value[i][j];
			}
			dp[i][j] = max(dpFromLeft[i][j], dpFromRight[i][j]);
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
	return 0;
}