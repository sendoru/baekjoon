#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int INF = 0x4fffffff;

int solve(vector<pair<int, int>>& dp, vector<vector<int>>& dist, int start, int enabled, int enabledCnt, int target)
{
	if (enabledCnt == target)
	{
		return 0;
	}

	pair<int, int>& ret = dp[enabled];
	if (ret.second >= 0)
	{
		return ret.second;
	}

	ret.second = INF;
	for (int here = 0; here < dist.size(); here++)
	{
		if (enabled & (1 << here))
		{
			for (int next = 0; next < dist.size(); next++)
			{
				if (enabled & (1 << next))
				{
					continue;
				}
				int c = dist[here][next] + solve(dp, dist, start, enabled + (1 << next), enabledCnt + 1, target);
				ret.second = min(ret.second, c);
			}
		}
	}

	return ret.second;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	string enabledStr;
	cin >> enabledStr;

	int p;
	cin >> p;

	int enabled = 0, enabledCnt = 0;
	for (int i = 0; i < enabledStr.length(); i++)
	{
		if (enabledStr[i] == 'Y')
		{
			enabled += 1 << i;
			enabledCnt++;
		}
	}

	if (enabledCnt >= p)
	{
		cout << 0 << '\n';
		return 0;
	}
	
	if (enabledCnt == 0)
	{
		cout << -1 << '\n';
		return 0;
	}

	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		if (enabled & (1 << i))
		{
			vector<pair<int, int>> dp(1ll << n, { 0, -1 });
			ans = min(ans, solve(dp, graph, i, enabled, enabledCnt, p));
		}
	}

	cout << ans << '\n';

	return 0;
}