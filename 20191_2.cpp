#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	cin >> s >> t;
	vector<vector<int>> dp(t.length(), vector<int>(26, -1));
	for (int i = t.length(); i >= 0; i--)
	{
		dp[t.length() - 1][t[i] - 'a'] = i;
	}
	for (int i = t.length() - 2; i >= 0; i--)
	{
		dp[i] = dp[i + 1];
		dp[i][t[i + 1] - 'a'] = i + 1;
	}
	int ans = 0, idx = t.length() - 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (dp[idx][s[i] - 'a'] == -1)
		{
			ans = -1;
			break;
		}
		if (dp[idx][s[i] - 'a'] <= idx)
			ans++;
		idx = dp[idx][s[i] - 'a'];
	}
	
	cout << ans;
	return 0;
}