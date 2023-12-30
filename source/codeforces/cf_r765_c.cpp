#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, l, k;
	cin >> n >> l >> k;
	// signs[i].first := 위치, signs[i].second := 속도
	vector<pair<ll, ll>> signs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> signs[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> signs[i].second;
	}
	signs.push_back({ l, signs.back().second });

	vector<vector<pair<ll, ll>>> dpSigns(n + 1, vector<pair<ll, ll>>(n + 1));
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 1e15 + 100000));
	dp[0][1] = (signs.back().first - signs[0].first) * signs[0].second;
	// i번째 sign이 무조건 마지막 sign이어야 함
	for (int i = 1; i < n; i++)
	{
		// j : 사용한 놈의 갯수
		for (int j = 2; j <= i + 1; j++)
		{
			for (int k = 0; k < i; k++)
			{
				// cout << dp[k][j - 1] + (signs.back().first - signs[i].first) * (signs[i].second - signs[k].second) << '\n';
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + (signs.back().first - signs[i].first) * (signs[i].second - signs[k].second));
			}
		}
	}

	ll ans = 1e9 + 100000;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - k; j <= n; j++)
		{
			ans = min(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}