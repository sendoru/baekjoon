#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<vector<int>>& dp, string& left, string& removed, string& t, int idx, int finger_cnt)
{

	if (idx + finger_cnt == t.length())
	{
		return 1;
	}
	if (left[idx] == t[idx + finger_cnt])
	{
		if (solve(dp, left, removed, t, idx + 1, finger_cnt))
		{
			return 1;
		}
	}
	if (finger_cnt == 2)
	{
		return 0;
	}
	if (t[idx + finger_cnt] == removed[finger_cnt])
	{
		if (solve(dp, left, removed, t, idx, finger_cnt + 1))
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	int n;
	cin >> n;
	string s, t, left, removed;
	cin >> s;
	cin >> t;
	int ii, jj;
	cin >> ii >> jj;
	for (int i = 0; i < n; i++)
	{
		if (i != ii && i != jj)
		{
			left += s[i];
		}
		else
		{
			removed += s[i];
		}
	}

	vector<vector<int>> dp(n, vector<int>(2, -1));
	cout << (solve(dp, left, removed, t, 0, 0) ? "YES" : "NO");
	return 0;
}