#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int INF = 1 << 20;

int dp[55][55][55][55];
int dpRect[55][55];

int solveRect(int n, int m)
{
	// 일단 무조건 n >= m으로 만들고 시작
	if (n < m) swap(n, m);
	if (m <= 0) return 0;
	int& ret = dpRect[n][m];
	if (ret != 0) return ret;
	if (n % m == 0) return ret = n / m;
	if (n >= 3 * m) return ret = 1 + solveRect(n - m, m);
	ret = INF;
	for (int i = 1; i <= n / 2; i++)
	{
		ret = min(ret, solveRect(i, m) + solveRect(n - i, m));
	}
	for (int i = 1; i <= m / 2; i++)
	{
		ret = min(ret, solveRect(n, i) + solveRect(n, m - i));
	}
	return ret;
}

int solve(int h1, int w1, int h2, int w2)
{
	// 일단 무조건 h1 >= w1으로 만들고 시작
	if (h1 < w1)
	{
		swap(h1, w1);
		swap(h2, w2);
	}
	if (h2 == 0 || w2 == 0)
	{
		h2 = 0; w2 = 0;
	}
	if (h1 <= 0 || w1 <= 0) return 0;
	int& ret = dp[h1][w1][h2][w2];
	if (ret != 0) return ret;
	if ((h2 == 0 || w2 == 0) && h1 % w1 == 0) return ret = h1 / w1;
	if ((h2 == 0 || w2 == 0) && h1 >= 3 * w1) return ret = 1 + solveRect(h1 - w1, h1);
	ret = INF;
	for (int i = 1; i < w1 - w2; i++)
	{
		ret = min(ret, solveRect(h1, i) + solve(h1, w1 - i, h2, w2));
	}
	ret = min(ret, solveRect(h1, w1 - w2) + solveRect(h1 - h2, w2));
	for (int i = w1 - w2 + 1; i < w1; i++)
	{
		ret = min(ret, solve(h1, i, h2, i + w2 - w1) + solveRect(h1 - h2, w1 - i));
	}
	for (int i = 1; i < h2; i++)
	{
		ret = min(ret, solveRect(i, w1 - w2) + solve(h1 - i, w1, h2 - i, w2));
	}
	ret = min(ret, solveRect(h2, w1 - w2) + solveRect(h1 - h2, w1));
	for (int i = h2 + 1; i < h1 ; i++)
	{
		ret = min(ret, solve(i, w1, h2, w2) + solveRect(h1 - i, w1));
	}
	return ret;
}

int main(void)
{
	int h1, w1, h2, w2;
	cin >> h1 >> w1 >> h2 >> w2;
	
	cout << solve(h1, w1, h2, w2);
	return 0;
}