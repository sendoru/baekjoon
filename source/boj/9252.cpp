#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	vector<vector<int> > dp(len1 + 1);

	for (int i = 0; i <= len1; i++)
	{
		for (int j = 0; j <= len2; j++)
		{
			dp[i].push_back(0);
		}
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[len1][len2] << '\n';

	stack<char> s;

	int i = len1, j = len2;
	while (i > 0 && j > 0)
	{
		if (dp[i][j] == dp[i][j - 1])
		{
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j])
		{
			i--;
		}
		else
		{
			i--; j--;
			s.push(s1[i]);
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	cout << '\n';
	return 0;

	return 0;
}