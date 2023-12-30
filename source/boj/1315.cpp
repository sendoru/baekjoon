#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> freePoints(1001, vector<int>(1001));
	vector<vector<bool>> reachable(1001, vector<bool>(1001));
	vector<vector<int>> missions(n, vector<int>(3));
	for (int i = 0; i < n; i++)
	{
		cin >> missions[i][0] >> missions[i][1] >> missions[i][2];
	}

	int ans = 0;
	for (int s = 1; s <= 1000; s++)
	{
		for (int i = 1; i <= 1000; i++)
		{
			freePoints[s][i] = 2 - s - i;
			int missionCnt = 0;
			for (int j = 0; j < missions.size(); j++)
			{
				if (missions[j][0] <= s || missions[j][1] <= i)
				{
					freePoints[s][i] += missions[j][2];
					missionCnt++;
				}
				reachable[s][i] = ((s == 1 && i == 1) || (s > 1 && reachable[s - 1][i] && freePoints[s - 1][i] > 0) || i > 1 && reachable[s][i - 1] && freePoints[s][i - 1] > 0);
				if (reachable[s][i])
					ans = max(ans, missionCnt);
			}
		}
	}
	cout << ans;
	return 0;
}