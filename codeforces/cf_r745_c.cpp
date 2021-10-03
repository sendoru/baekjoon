#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> makeDPTable(vector<string>& blocks)
{
	/*
	* d = 0 -> 오른쪽
	* d = 1 -> 아래
	* d = 2 -> 왼쪽
	* d = 3 -> 위
	* d = 0일때 오른쪽에서 시작해서 반시계 방향으로 돌아감
	* dp[r][c][d] -> r, c에서 시작해서 d 방향으로 갈 때 최대로 연속한 1의 갯수
	*/
	vector<int> dr = { 0, 1, 0, -1};
	vector<int> dc = { 1, 0, -1, 0 };
	int rSize = blocks.size(), cSize = blocks[0].length();
	vector<vector<vector<int>>> dp(rSize, vector<vector<int>>(cSize, vector<int>(4, -1)));
	for (int r = 0; r < rSize; r++)
	{
		for (int c = 0; c < cSize; c++)
		{
			if (blocks[r][c] == '0')
			{
				for (int d = 0; d < 4; d++)
				{
					dp[r][c][d] = 0;
				}
				continue;
			}
			for (int d = 0; d < 4; d++)
			{
				if (dp[r][c][d] != -1)
				{
					continue;
				}
				int nextR = r, nextC = c, cnt = 1;
				while (nextR >= 0 && nextR < rSize && nextC >= 0 && nextC < cSize && blocks[nextR][nextC] == '1')
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
				while (nextR != r && nextC != c)
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<string> blocks(n);
		for (int i = 0; i < n; i++) cin >> blocks[i];
		auto dp = makeDPTable(blocks);
		
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

	}

	return 0;
}