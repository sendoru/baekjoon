#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll divCeil(ll a, ll b)
{
	if (a % b == 0) return a / b;
	return a / b + 1;
}

ll cost(ll c, ll divisor)
{
	return divCeil(c, divisor) * divisor - c;
}

ll gcd(ll a, ll b)
{
	if (a == 0) return 0;
	return gcd(b % a, a);
}

ll arrayGCD(vector<ll>& seq)
{
	ll ret = seq[0];
	for (int i = 1; i < seq.size(); i++)
	{
		ret = gcd(seq[i], ret);
		if (ret == 1) return ret;
	}
	return ret;
}

int main(void)
{
	ll n, k, ans = 0;
	cin >> n >> k;
	vector<ll> a(n);
	ll aMax = 0, aSum = 0, maxDiff = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		aMax = max(aMax, a[i]);
		aSum += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		maxDiff += aMax - a[i];
	}
	if (k >= maxDiff)
	{
		ans = aMax;
		k -= maxDiff;
		ans += k / n;
	}
	else
	{
		int ans = 1;
		vector<ll> sum(aMax + 1), cnt(aMax + 1);
		for (ll elem : a)
		{
			sum[elem] += elem;
			cnt[elem]++;
		}

		for (int i = 2; i <= aMax; i++)
		{
			ll v = 0;
			for (int j = 0; j <= aMax / i; j++)
			{
				int r = min((int)aMax, (j + 1) * i - 1);
				int l = i * j;

			}
		}
	}
	cout << ans;
	return 0;
}