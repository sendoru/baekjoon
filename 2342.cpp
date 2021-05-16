#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// . 1 . //
	// 2 0 4 //
	// . 3 . //
	vector<vector<int> > cost(5);
	cost[0] = { 0, 2, 2, 2, 2 };
	cost[1] = { 2, 1, 3, 4, 3 };
	cost[2] = { 2, 3, 1, 3, 4 };
	cost[3] = { 2, 4, 3, 1, 3 };
	cost[4] = { 2, 3, 4, 3, 1 };

	vector<int> notes;
	int temp, ans = 0;
	while (true)
	{	
		cin >> temp;
		if (temp == 0)
		{
			break;
		}
		notes.push_back(temp);
	}

	if (notes.size() == 0)
	{
		cout << 0 << '\n';
		return 0;
	}

	vector<vector<vector<int> > > dp(notes.size(), vector<vector<int> >(5, vector<int> (5, INF)));
	dp[0][notes[0]][0] = 2;
	dp[0][0][notes[0]] = 2;

	for (int i = 1; i < notes.size(); i++)
	{
		// i번째 노트를 오른발로 밟는 경우
		for (int left = 0; left < 5; left++)
		{
			for (int right = 0; right < 5; right++)
			{
				dp[i][left][notes[i]] = min(dp[i][left][notes[i]], dp[i - 1][left][right] + cost[right][notes[i]]);
			}
		}
		// i번째 노트를 왼발로 밟는 경우
		for (int right = 0; right < 5; right++)
		{
			for (int left = 0; left < 5; left++)
			{
				dp[i][notes[i]][right] = min(dp[i][notes[i]][right], dp[i - 1][left][right] + cost[left][notes[i]]);
			}
		}
	}

	ans = INF;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ans = min(ans, dp[notes.size() - 1][i][j]);
		}
	}

	cout << ans << '\n';
	return 0;
}