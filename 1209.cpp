#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
constexpr int INF = (int)2e9;
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> aSorted(n);
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		aSorted[i].first = a[i];
		aSorted[i].second = i;
	}
	sort(aSorted.begin(), aSorted.end());
	for (int i = 0; i < 2; i++)
	{
		for (int i = 0; i < n; i++)
		{
			aSorted[i].first = a[i];
			aSorted[i].second = i;
		}
		sort(aSorted.begin(), aSorted.end());

		// f_i(x) = a[0:i]에 대해 b의 모든 원소가 x 이하일 때의 부분해
		// dp[i][j]= f_i(a[j])
		vector<vector<int>> dp(n, vector<int>(n, INF));
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= a[0])
			{
				dp[0][i] = 0;
			}
			else
			{
				dp[0][i] = a[0] - a[i];
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int tmp = abs(a[i] - aSorted[j].first) + dp[i - 1][aSorted[j].second];
				if (j == 0)
				{
					dp[i][aSorted[j].second] = tmp;
				}
				else
				{
					dp[i][aSorted[j].second] = min(tmp, dp[i][aSorted[j - 1].second]);
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			ans = min(ans, dp[n - 1][i]);
		}
		reverse(a.begin(), a.end());
	}
	cout << ans;
	return 0;
}