#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll>sizes(n);

		for (int i = 0; i < n; i++)
		{
			cin >> sizes[i];
		}

		// dp[i][j] := j번 ~ i번 파일까지 합쳤을 때의 {용량, 최소비용}
		vector<vector < pair<ll, ll> > > dp(n, vector<pair<ll, ll> >(n + 1, { 0, 0 }));

		for (int i = 1; i < n; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (j == i)
				{
					dp[i][j] = { sizes[i], 0 };
				}
				else if (j == i - 1)
				{
					dp[i][j] = { sizes[i] + sizes[j], sizes[i] + sizes[j] };
				}
				else
				{
					ll minCost = 1ll << 40, t = 0, curSize = dp[i][j + 1].first + sizes[j];
					while (j + t < i)
					{
						minCost = min(minCost, dp[j + t][j].second + dp[i][j + t + 1].second + curSize);
						t++;
					}
					dp[i][j] = { curSize, minCost };
				}
			}
		}

		cout << dp[n - 1][0].second << '\n';
	}
	return 0;
}