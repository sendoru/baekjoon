#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int INF = 0x3fffffff;

int checkPal(string& str, vector<vector<int>>& isPal, int start, int end)
{
	int& ret = isPal[start][end];
	if (ret != -1)
	{
		return ret;
	}
	if (start == end || (start + 1 == end && str[start] == str[end]))
	{
		ret = 1;
		return ret;
	}
	if (str[start] != str[end])
	{
		ret = 0;
		return ret;
	}
	ret = checkPal(str, isPal, start + 1, end - 1);
	return ret;
}

int solve(string& str, vector<vector<int>>& isPal, vector<int>& dp, int start)
{
	int& ret = dp[start];
	if (ret != INF)
	{
		return ret;
	}
	if (start == str.length())
	{
		return ret = 0;
	}
	for (int i = start; i < str.length(); i++)
	{
		if (checkPal(str, isPal, start, i))
		{
			if (i == str.length() - 1)
			{
				ret = 1;
			}
			else
			{
				ret = min(ret, 1 + solve(str, isPal, dp, i + 1));
			}
		}
	}
	return ret;
}

int main(void)
{
	string str;
	cin >> str;
	int sLen = str.length();

	// isPal[s][e] : s부터 e까지 잘라놓은 문자열이 팰린드롬이면 1, 아니면 0
	// 처음에는 -1로 초기화
	vector<vector<int>> isPal(sLen, vector<int>(sLen, -1));

	// dp[s] : s부터 문자열 끝까지만 봤을 때 필요한 최소 분할 갯수
	vector<int> dp(sLen, INF);

	cout << solve(str, isPal, dp, 0) << '\n';
	return 0;
}