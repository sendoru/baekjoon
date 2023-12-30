#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
int decimalMod[51];

ll factorial(ll a)
{
	ll ret = 1;
	for (int i = 1; i <= a; i++)
	{
		ret *= i;
	}
	return ret;
}

ll getGCD(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	return getGCD(b, a % b);
}

int getMod(string& s, int k)
{
	int ret = 0;
	for (int i = 0; i < s.length(); i++)
	{
		ret = (ret * 10 + s[i] - '0') % k;
	}
	return ret;
}

ll solve(vector<string>& sequence, vector<int>& sequenceMod, vector<vector<ll>>& dp, int k, int curNum, int flag)
{
	if (flag == (1 << sequence.size()) - 1)
	{
		return curNum ? 0 : 1;
	}
	ll& ret = dp[curNum][flag];
	if (ret != -1)
	{
		return ret;
	}
	ret = 0;
	for (int i = 0; i < sequence.size(); i++)
	{
		if (!(flag & (1 << i)))
		{
			ret += solve(sequence, sequenceMod, dp, k, (curNum * decimalMod[sequence[i].size()] + sequenceMod[i]) % k, flag | (1 << i));
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;
	vector<string> sequence(n);
	vector<int> sequenceMod(n);
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	cin >> k;
	vector<vector<ll>> dp(k, vector<ll>(1ll << n, -1));
	for (int i = 0; i < n; i++)
	{
		sequenceMod[i] = getMod(sequence[i], k);
	}
	decimalMod[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		decimalMod[i] = decimalMod[i - 1] * 10 % k;
	}
	ll correctCnt = solve(sequence, sequenceMod, dp, k, 0, 0);
	ll totalCnt = factorial(n);
	ll gcd = getGCD(correctCnt, totalCnt);
	correctCnt /= gcd;
	totalCnt /= gcd;
	cout << correctCnt << '/' << totalCnt << '\n';
	return 0;
}