#include <iostream>
#include <vector>
using namespace std;
constexpr double INF = 4'000'000'000'000;
vector<vector<double>> mse(4001, vector<double>(4001, -1.));
vector<int> freqSum(4001), freqSquareSum(4001);

double getMSE(int s, int e)
{
	return freqSquareSum[e] - freqSquareSum[s - 1] - (double)(freqSum[e] - freqSum[s - 1]) * (freqSum[e] - freqSum[s - 1]) / (double)(e-s+1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int b;
	cin >> b;
	int n;
	cin >> n;
	vector<int> freq(4001);
	for (int i = 1; i <= n; i++)
	{
		cin >> freq[i];
	}

	for (int i = 1; i <= 4000; i++)
	{
		freqSum[i] = freqSum[i - 1] + freq[i];
		freqSquareSum[i] = freqSquareSum[i - 1] + (freq[i] * freq[i]);
	}

	// mse[s][e] = freqSquareSum[e] - freqSquareSum[s - 1] - (freqSum[e] - freqSum[s - 1]) * (freqSum[e] - freqSum[s - 1]);

	double ans = INF;
	vector<vector<double>> dp(b + 1, vector<double>(4001));
	for (int i = 1; i <= n; i++)
	{
		dp[1][i] = getMSE(1, i);
	}
	ans = min(ans, dp[1][n]);

	for (int i = 2; i <= b; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = INF;
			for (int k = 1; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + getMSE(k + 1, j));
			}
		}
		ans = min(ans, dp[i][n]);
	}
	cout.precision(7);
	cout << fixed << ans;
	return 0;
}