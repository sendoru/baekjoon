#include <iostream>
#include <functional>
#include <vector>
#include <string>
using namespace std;
constexpr int MOD = 10007;

int solve(string& s)
{
	// dp[i][j] := i ~ j까지 봤을 때 답
	vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
	for (int i = 0; i < dp.size(); i++)
	{
		dp[i][i] = 1;
		for (int j = 0; j < i; j++)
		{
			dp[i][j] = 0;
		}
	}
	function<int(int, int)> innerDP = [&] (int l, int r) -> int
	{
		int& ret = dp[l][r];
		if (l == r) return ret = 1;
		if (l > r) return ret = 0;
		if (ret != -1) return ret;
		return ret = (innerDP(l + 1, r) + innerDP(l, r - 1) - innerDP(l + 1, r - 1) + (int)(s[l] == s[r]) * (innerDP(l + 1, r - 1) + 1) + 10 * MOD) % MOD;
	};

	int ret = innerDP(0, s.length() - 1);
	return ret;
}

int main(void)
{
	string s;
	cin >> s;
	cout << solve(s);
	return 0;
}
