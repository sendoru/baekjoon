#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MOD = 100;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> dp(MOD, vector<int>(MOD));
	vector<vector<int>> connected(MOD, vector<int>(MOD));
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		connected[a][b] = 1;
		connected[b][a] = 1;
	}
	int ans = 0;
	for (int i = 0; i < MOD; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			for (int k = j; k < i; k++)
			{
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + connected[j][i]);
			}
			ans = max(ans, dp[j][i]);
		}
	}

	cout << ans;
	return 0;
}