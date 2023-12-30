#include <iostream>
#include <vector>
#define INF 0x3fffffff

using namespace std;

int solve(vector<vector<int>>& dp, vector<vector<int>>& cost, int n, int cur, int bitField)
{
	if (dp[cur][bitField])
	{
		return dp[cur][bitField];
	}
	if (bitField == (1 << n) - 1)
	{
		return 0;
	}
	int ret = INF;
	for (int i = 0; i < n; i++)
	{
		if (!(bitField & (1 << i)))
		{
			bitField |= (1 << i);
			ret = min(ret, solve(dp, cost, n, cur + 1, bitField) + cost[cur][i]);
			bitField &= ~(1 << i);
		}
	}
	dp[cur][bitField] = ret;
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> cost(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}
	// dp[i][j]
	// i := 지금까지 처리한 일의 갯수
	// j := 지금까지 한 일의 번호를 나타대는 비트마스킹
	vector<vector<int>> dp(n + 1, vector<int>(1 << n));
	cout << solve(dp, cost, n, 0, 0) << '\n';
	return 0;
}