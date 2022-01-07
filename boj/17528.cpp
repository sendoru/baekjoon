#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int INF = 0x3fffffff;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	// dp[i][j] : i는 현재까지 시행한 작업 번호, j는 a가 소모한 시간, dp[i][j]는 b가 소모한 시간의 최솟값
	vector<vector<int>> dp(n + 1, vector<int>(250 * n + 1, INF));
	dp[0][a[0]] = 0;
	dp[0][0] = b[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < dp[i].size(); j++)
		{
			if (dp[i - 1][j] == INF)
				continue;
			// 현재 작업을 a번에서 처리할때
			dp[i][j + a[i]] = dp[i - 1][j];
			// 현재 작업을 b번에서 처리할 때
			dp[i][j] = dp[i - 1][j] + b[i];
		}
	}

	int ans = INF;
	for (int i = 0; i < dp[n - 1].size(); i++)
		if (max(i, dp[n - 1][i]) < ans)
			ans = max(i, dp[n - 1][i]);

	cout << ans;
	return 0;
}