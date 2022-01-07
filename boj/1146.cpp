#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1000000;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<ll> > dp(n + 1, vector<ll>(n + 1));
	if (n == 1)
	{
		cout << 1 << '\n';
	}
	else if (n == 2)
	{
		cout << 2 << '\n';
	}
	else
	{
		
		dp[3][2] = 1; dp[3][3] = 1;
		for (int i = 3; i < n; i++)
		{
			for (int j = i; j >= 2; j--)
			{
				for (int k = i + 1; k > i + 1 - j; k--)
				{
					dp[i + 1][k] += dp[i][j];
					dp[i + 1][k] %= MOD;
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += 2 * dp[n][i];
			ans %= MOD;
		}
		cout << ans << '\n';
	}

	return 0;
}

