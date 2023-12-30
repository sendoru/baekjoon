#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll solve(ll n)
{
	if (n <= 0) return 0;
	if (n <= 9) return 1;

	ll ret = 0;
	ll lg = (ll)log10(n);
	ll lower = (ll)powl(10ll, lg);
	ll highestDigit = n / lower;

	for (int i = 0; i < lg; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			ret += (ll)powl(10ll, j);
		}
	}

	if (highestDigit >= 2)
	{
		for (int i = 0; i <= lg; i++)
		{
			ret += (ll)powl(10ll, i);
		}
		return ret;
	}

	ret += n - lower + 1;
	if (n - lower >= lower / 10ll)
		ret += solve(n - lower) - solve(lower / 10ll - 1ll);
	return ret;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}