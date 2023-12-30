#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	vector<vector<string>> rotated(4, vector<string>(n));
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	// s1: 반시계 90도
	for (int i = 0; i < n; i++)
	{
		rotated[0][i] = s[i];
		rotated[1][i] = s[i];
		rotated[2][i] = s[i];
		rotated[3][i] = s[i];
		for (int j = 0; j < n; j++)
		{
			rotated[0][i][j] = s[i][j];
			rotated[1][i][j] = s[j][n - i - 1];
			rotated[2][i][j] = s[n - i - 1][n - j - 1];
			rotated[3][i][j] = s[n - j - 1][i];
		}
	}

	bool ans = false;
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> UpperLeftS = { 2 * n, 2 * n }, LowerRightS = { -1, -1 }, UpperLeftT = { 2 * n, 2 * n }, LowerRightT = { -1, -1 };
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				if (rotated[i][r][c] == '#')
				{
					UpperLeftS.first = min(UpperLeftS.first, r);
					UpperLeftS.second = min(UpperLeftS.second, c);
					LowerRightS.first = max(LowerRightS.first, r);
					LowerRightS.second = max(LowerRightS.second, c);
				}
			}
		}
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				if (t[r][c] == '#')
				{
					UpperLeftT.first = min(UpperLeftT.first, r);
					UpperLeftT.second = min(UpperLeftT.second, c);
					LowerRightT.first = max(LowerRightT.first, r);
					LowerRightT.second = max(LowerRightT.second, c);
				}
			}
		}

		if (LowerRightS.first - UpperLeftS.first != LowerRightT.first - UpperLeftT.first || LowerRightS.second - UpperLeftS.second != LowerRightT.second - UpperLeftT.second)
		{
			continue;
		}
		bool impossible = false;
		for (int r = 0; r < LowerRightS.first - UpperLeftS.first + 1; r++)
		{
			for (int c = 0; c < LowerRightS.second - UpperLeftS.second + 1; c++)
			{
				if (rotated[i][UpperLeftS.first + r][UpperLeftS.second + c] != t[UpperLeftT.first + r][UpperLeftT.second + c])
				{
					impossible = true;
					break;
				}
			}
			if (impossible)
				break;
		}
		if (!impossible)
		{
			ans = true;
			break;
		}
	}

	cout << (ans ? "Yes" : "No");
	return 0;
}