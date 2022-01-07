#include <iostream>
#include <vector>

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

	int n, maxLen = 0;
	cin >> n;
	vector<int> sequence(n);
	// dp[i][0]: 바이토닉 수열이 증가하고 있을 때
	// dp[i][1]: 바이토닉 수열이 감소하고 있을 때
	vector<vector<int> > dp(n, vector<int>({ 1, 1 }));
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	dp[0][0] = 1;
	dp[0][1] = 1;

	for (int i = 0; i < n; i++)
	{
		int end = sequence[i];
		for (int j = 0; j < i; j++)
		{
			if (end > sequence[j])
			{
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
			if (end < sequence[j])
			{
				dp[i][1] = max(dp[i][1], max(dp[j][0] + 1, dp[j][1] + 1));
			}
		}
		maxLen = max(maxLen, max(dp[i][0], dp[i][1]));
	}

	cout << maxLen << endl;

	return 0;
}