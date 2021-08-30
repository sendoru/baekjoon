#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<vector<int>>> makeDPTable(vector<string>& mine)
{
	int rSize = mine.size(), cSize = mine[0].size();
	vector<int> dr = { 1, 1, -1, -1 }, dc = { 1, -1, -1, 1 };
	/*
	* d = 0 -> 오른쪽 아래
	* d = 1 -> 왼쪽 아래
	* d = 2 -> 왼쪽 위
	* d = 3 -> 오른쪽 위
	* d = 0일때 오른쪽 아래에서 시작해서 반시계 방향으로 돌아감
	* dp[r][c][d] -> r, c에서 시작해서 d 방향으로 갈 때 최대로 연속한 1의 갯수
	*/
	vector<vector<vector<int>>> dp(rSize, vector<vector<int>>(cSize, vector<int>(4, -1)));
	for (int r = 0; r < rSize; r++)
	{
		for (int c = 0; c < cSize; c++)
		{
			if (mine[r][c] == '0')
			{
				for (int d = 0; d < 4; d++)
				{
					dp[r][c][d] = 0;
				}
			}
			for (int d = 0; d < 4; d++)
			{
				if (dp[r][c][d] != -1)
				{
					continue;
				}
				int nextR = r, nextC = c, cnt = 1;
				while (nextR >= 0 && nextR < rSize && nextC >= 0 && nextC < cSize && mine[nextR][nextC] == '1')
				{
					nextR += dr[d];
					nextC += dc[d];
					cnt++;
				}
				nextR -= dr[d];
				nextC -= dc[d];
				cnt--;
				dp[nextR][nextC][d] = 1;
				dp[nextR][nextC][(d + 2) % 4] = cnt;
				while (nextR != r)
				{
					nextR -= dr[d];
					nextC -= dc[d];
					dp[nextR][nextC][d] = dp[nextR + dr[d]][nextC + dc[d]][d] + 1;
					dp[nextR][nextC][(d + 2) % 4] = dp[nextR + dr[d]][nextC + dc[d]][(d + 2) % 4] - 1;
				}
			}
		}
	}

	return dp;
}

int main(void)
{
	int rSize, cSize;
	cin >> rSize >> cSize;
	int maxSize = min(rSize / 2 + rSize % 2, cSize / 2 + cSize % 2);
	vector<string> mine(rSize);
	for (int i = 0; i < rSize; i++)
	{
		cin >> mine[i];
	}
	auto dp = makeDPTable(mine);
	/*
	for (int r = 0; r < dp.size(); r++)
	{
		for (int c = 0; c < dp[0].size(); c++)
		{
			for (int d = 0; d < 4; d++)
			{
				cout << dp[r][c][d] << ' ';
			}
			cout << "  ";
		}
		cout << '\n';
	}
	*/
	int ans = 0;
	for (int r = 0; r < rSize; r++)
	{
		for (int c = 0; c < cSize; c++)
		{
			if (mine[r][c] == '0') continue;
			// mine[r][c]를 위쪽 꼭짓점이라고 가정하면
			ans = max(ans, 1);
			for (int s = min(dp[r][c][0], dp[r][c][1]); s > ans; s--)
			{
				if (r + 2 * (s - 1) >= rSize || c - (s - 1) < 0 || c + (s - 1) >= cSize) continue;
				if (dp[r + 2 * (s - 1)][c][2] >= s && dp[r + 2 * (s - 1)][c][3] >= s)
				{
					ans = s;
					break;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}