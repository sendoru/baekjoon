#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll powll(ll base, ll exp)
{
	if (exp == 0)
		return 1;
	if (exp & 1)
		return powll(base, exp / 2) * powll(base, exp / 2) * base;
	return powll(base, exp / 2) * powll(base, exp / 2);
}

void solve2(ll n, ll k, bool ch)
{
	if (n == 0) return;
	if (k < 0) return;
	if (!ch)
	{
		if (n == 0) return;
		if (k == 0)
		{
			for (int i = 0; i < n; i++) cout << 0;
			return;
		}
		k--;
	
		ll cnt = 0;
		for (int zeroCnt = n - 1; zeroCnt >= 1; zeroCnt--)
		{
			cnt += 1 * 6 * powll(16, n - zeroCnt - 1);
		}
		if (k < cnt)
		{
			int zeroCnt = n - 1;
			while (true)
			{
				if (k - 6 * powll(16, n - zeroCnt - 1) >= 0)
				{
					k -= 6 * powll(16, n - zeroCnt - 1);
					zeroCnt--;
				}
				else break;
			}

			for (int i = 0; i < zeroCnt; i++) cout << 0;
			solve2(n - zeroCnt, k, true);
			return;
		}

		k -= cnt;

		for (int i = 1; i <= n; i++)
		{
			// zeroCnt = n - i;
			cnt = 0;
			cnt += 1;
			for (int zeroCnt = n - i - 1; zeroCnt >= 0; zeroCnt--)
			{
				cnt += 6 * powll(16, n - i - zeroCnt - 1);
			}

			ll targetNum = (k) / cnt + powll(10, i - 1);
			if (targetNum < powll(10, i))
			{
				int numLen = i;
				if ((targetNum - powll(10, i - 1)) * cnt == k )
				{
					for (int j = 0; j < n - numLen; j++) cout << 0;
					cout << targetNum;
					return;
				}
				k -= cnt * (targetNum - powll(10, i - 1));
				k -= 1;
				numLen = n - 1;
				while (true)
				{
					if (k - 6 * powll(16, n - numLen - 1) >= 0)
					{
						k -= 6 * powll(16, n - numLen - 1);
						numLen--;
					}
					else break;
				}
				// if (numLen != n - 1) numLen++;
				for (int j = 0; j < numLen - i; j++) cout << 0;
				cout << targetNum;
				solve2(n - numLen, k, true);
				return;
			}

			k -= powll(10, i - 1) * 9 * cnt;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (k < powll(16, n - 1))
		{
			cout << (char)(i + 'a');
			solve2(n - 1, k, false);
			return;
		}
		k -= powll(16, n - 1);
	}
	return;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		k--;
		solve2(n, k, false);
		cout << '\n';
	}
}