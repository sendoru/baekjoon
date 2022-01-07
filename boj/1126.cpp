#include <iostream>
#include <vector>
constexpr int MAX = 500'001;
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> blocks(n);
	// dp[i] := 높이차가 i일 때, 둘 중 더 높은 것의 최대 높이
	vector<int> dp(MAX, -1);
	for (int i = 0; i < n; i++)
		cin >> blocks[i];
	
	for (int i = 0; i < n; i++)
	{
		// 이전에 쌓아뒀던 것들에서 i번째 블록을 잘 추가하는 경우
		vector<int> dpTemp = dp;
		for (int j = 0; j < MAX; j++)
		{
			if (dp[j] == -1) continue;
			// 더 높은 쪽에 쌓는 경우
			dpTemp[j + blocks[i]] = max(dpTemp[j + blocks[i]], dp[j] + blocks[i]);
			// 더 낮은 쪽에 쌓는 경우
			dpTemp[abs(j - blocks[i])] = max(dpTemp[abs(j - blocks[i])], max(dp[j], dp[j] - j + blocks[i]));
		}
		// i번째 블록 하나만 쓰는 경우
		dpTemp[blocks[i]] = max(dpTemp[blocks[i]], blocks[i]);
		dp = dpTemp;
	}
	
	cout << dp[0];
	return 0;
}