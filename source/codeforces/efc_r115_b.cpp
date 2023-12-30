#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> attend(n, vector<int>(5));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> attend[i][j];
			}
		}

		bool ans = false;
		for (int d1 = 0; d1 < 5; d1++)
		{
			for (int d2 = d1 + 1; d2 < 5; d2++)
			{
				int d1Cnt = 0, d2Cnt = 0, totalCnt = 0;
				for (int std = 0; std < n; std++)
				{
					if (attend[std][d1] == 1) d1Cnt++;
					if (attend[std][d2] == 1) d2Cnt++;
					if ((attend[std][d1] == 1) || (attend[std][d2] == 1)) totalCnt++;
				}
				if (totalCnt == n && d1Cnt >= n / 2 && d2Cnt >= n / 2)
				{
					ans = true;
					break;
				}
			}
			if (ans) break;
		}
		
		cout << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}