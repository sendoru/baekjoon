#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll solve(int n, int l, int r, vector<vector<vector<ll>>>& dp)
{
	if (l == 0 || r == 0 || ((l > 0 || r > 0) && n == 0)) return 0;
	if ((l == n && r == 1) || (r == n && l == 1)) return 1;
	ll& ret = dp[n][l][r];
	if (ret != -1) return ret;
	ret = 0;
	// n개 중에 제일 작은 걸 제거했는데 왼쪽에서 보이는 갯수가 1개 줄음: solve(n - 1, l - l, r, dp) <- 제일 작은 게 왼쪽에 있던 경우 (경우의 수 = 1)
	// n개 중에 제일 작은 걸 제거했는데 오른쪽에서 보이는 갯수가 1개 줄음: solve(n - 1, l, r - 1, dp) <- 제일 작은 게 오른쪽에 있던 경우 (경우의 수 = 1)
	// n개 중에 제일 작은 걸 제거했는데 보이는 갯수가 같음: solve(n - 1, l, r, dp) (경우의 수 = n - 2)
	ret = (solve(n - 1, l, r, dp) * (n - 2) + solve(n - 1, l - 1, r, dp) + solve(n - 1, l, r - 1, dp)) % MOD;
	return ret;
}

int main(void)
{
	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1)));
	cout << solve(n, l, r, dp) % MOD << '\n';
	return 0;
}