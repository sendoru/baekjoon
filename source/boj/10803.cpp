#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int INF = 1 << 20;

int solve(vector<vector<int>>& dp, int n, int m)
{
	// 일단 무조건 n >= m으로 만들고 시작
	if (n < m) swap(n, m);
	if (n <= 0) return 0;
	int& ret = dp[n][m];
	if (ret != -1) return ret;
	if (n % m == 0) return ret = n / m;
	if (n >= 3 * m) return ret = 1 + solve(dp, n - m, m);
	ret = INF;
	for (int i = 1; i <= n / 2; i++)
	{
		ret = min(ret, solve(dp, i, m) + solve(dp, n - i, m));
	}
	for (int i = 1; i <= m / 2; i++)
	{
		ret = min(ret, solve(dp, n, i) + solve(dp, n, m - i));
	}
	return ret;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	if (n < m) swap(n, m);
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	cout << solve(dp, n, m);
	return 0;
}