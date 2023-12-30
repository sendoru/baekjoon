#include <iostream>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

void factorize(map<ll, ll>& primes, ll n)
{
	ll smallestPrime = 2;
	while (smallestPrime * smallestPrime <= n)
	{
		if (n % smallestPrime == 0)
		{
			n /= smallestPrime;
			primes[smallestPrime]++;
		}
		else
		{
			smallestPrime++;
		}
	}
	primes[n]++;
}

int main(void)
{
	ll n;
	cin >> n;

	ll ans = 0;
	for (ll i = 2; i <= n; i++)
	{
		map<ll, ll> primes;
		ll result = 1;
		factorize(primes, i);
		for (auto iter = primes.begin(); iter != primes.end(); iter++)
		{
			result *= pow(iter->first, iter->second - 1);
			result *= iter->first - 1;
		}
		ans += result;
	}
	cout << ans;
	return 0;
}