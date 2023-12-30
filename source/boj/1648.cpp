#include <iostream>
#include <vector>
#include <functional>
typedef long long ll;
using namespace std;
constexpr int MOD = 9901;

vector<int> generateComb(int m)
{
	vector<int> ret;
	vector<int> curComb;
	function<void(int, int)> f = [&] (int m, int toPick) -> void
	{
		if (toPick == 0)
		{
			ret.push_back(0);
			for (auto elem : curComb)
			{
				ret.back() += 1 << elem;
				ret.back() += 1 << (elem + 1);
			}
			return;
		}
		int smallest = curComb.empty() ? 0 : curComb.back() + 2;
		for (int next = smallest; next <= m - 2; next++)
		{
			curComb.push_back(next);
			f(m, toPick - 1);
			curComb.pop_back();
		}
	};

	for (int i = 0; i <= m / 2; i++)
	{
		f(m, i);
	}
	return ret;
}

int solve(int n, int m)
{
	if ((n * m) % 2 != 0) return 0;
	// dp[i][j] = 바로 위 칸까지 꽉 채워졌을 때, 현재 칸의 비트마스킹 상태를 j로 만드는 경우의 수
	vector<vector<int>> dp(n, vector<int>(1 << m));
	int maxBitMask = (1 << m) - 1;
	auto comb = generateComb(m);
	for (auto curComb : comb)
	{
		dp[0][curComb] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < (1 << m); j++)
		{
			for (auto curComb : comb)
			{
				if ((curComb & j) == curComb)
				{
					dp[i][j] += dp[i - 1][maxBitMask ^ (j - curComb)];
					dp[i][j] %= MOD;
				}
			}
		}
	}

	return dp.back().back();
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	cout << solve(n, m);
	return 0;
}