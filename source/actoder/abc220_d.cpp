#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	// dp[i][j][k] := 남은 수열의 길이가 i일때, 맨 끝이 j, 끝에서 2번째가 k가 되게 하는 경우의 수
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(10, vector<ll>(10)));
	dp[n][a[0]][a[1]] = 1;
	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				dp[n - i + 1][(j + k) % 10][a[i]] += dp[n - i + 2][j][k];
				dp[n - i + 1][(j + k) % 10][a[i]] %= MOD;
				dp[n - i + 1][(j * k) % 10][a[i]] += dp[n - i + 2][j][k];
				dp[n - i + 1][(j * k) % 10][a[i]] % MOD;
			}
		}
	}
	vector<ll> ans(10);
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 10; k++)
		{
			ans[(j + k) % 10] += dp[2][j][k];
			ans[(j + k) % 10] %= MOD;
			ans[(j * k) % 10] += dp[2][j][k];
			ans[(j * k) % 10] %= MOD;
		}
	}
	for (ll elem : ans) cout << elem << '\n';
	return 0;
}