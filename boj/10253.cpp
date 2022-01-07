#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll getGCD(ll a, ll b)
{
	if (b == 0) return a;
	return getGCD(b, a % b);
}

ll solve(ll num, ll den)
{
	int x = 1;
	while (num != 1)
	{
		for (;; x++)
		{
			if (den <= x * num)
			{
				break;
			}
		}
		num = num * x - den;
		den = den * x;
		ll gcd = getGCD(num, den);
		num /= gcd; den /= gcd;
	}

	return den;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		ll num, den;
		cin >> num >> den;
		cout << solve(num, den) << '\n';
	}

	return 0;
}

