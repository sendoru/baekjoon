#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int getGCD(ll p, ll q)
{
	if (q == 0) return p;
	return getGCD(q, p % q);
}

// TODO
int solve(ll d, ll p, ll q)
{
	ll gcd = getGCD(p, q);
	if (p > q) swap(p, q);
	if (p == 1) return d;
	if (q == 2) return d % 2 == 0 ? d : d + 1;
	if (p == 2 && q == 3) return d <= 1 ? 2 : d;
	if (p == q) return q * (d / q + (ll)(d % q != 0));
	if (d > p * q) return gcd * (d / gcd + (ll)(d % gcd != 0));

	ll ans = q * (d / q + (ll)(d % q != 0)), newAns;
	ll qCnt = d / q + (ll)(d % q != 0), remainder, pCnt;
	while (qCnt--)
	{
		remainder = d - q * qCnt;
		pCnt = remainder / p + (ll)(remainder % p != 0);
		newAns = q * qCnt + p * pCnt;
		if (newAns >= d && newAns < ans)
		{
			ans = newAns;
		}
	}
	return ans;
}

int naiveSolve(ll d, ll p, ll q)
{
	ll gcd = getGCD(p, q);
	if (p > q) swap(p, q);
	if (p == 1) return d;
	if (q == 2) return d % 2 == 0 ? d : d + 1;
	if (p == 2 && q == 3) return d <= 1 ? 2 : d;
	if (p == q) return q * (d / q + (ll)(d % q != 0));
	// if (d > p * q) return gcd * (d / gcd + (ll)(d % gcd != 0));

	ll ans = q * (d / q + (ll)(d % q != 0)), newAns;
	ll qCnt = d / q + (ll)(d % q != 0), remainder, pCnt;
	while (qCnt--)
	{
		remainder = d - q * qCnt;
		pCnt = remainder / p + (ll)(remainder % p != 0);
		newAns = q * qCnt + p * pCnt;
		if (newAns >= d && newAns < ans)
		{
			ans = newAns;
		}
	}
	return ans;
}

void test(int cnt)
{

	mt19937 rand((unsigned int)time(NULL));
	uniform_int_distribution<int> dist(1, 1e9 - 2);
	uniform_int_distribution<int> smallDist(1, 1e4 - 2);
	int errCnt = 0;
	for (int i = 0; i < cnt / 2; i++)
	{
		int d = dist(rand), p = dist(rand), q = dist(rand);
		int naiveRes = naiveSolve(d, p, q), res = solve(d, p, q);
		if (naiveRes != res)
		{
			cout << "Error! " << "d = " << d << ", p = " << p << ", q = " << q << "\n";
			cout << "naiveSolve: " << naiveRes << ", solve: " << res << "\n\n";
			errCnt++;
		}
	}
	for (int i = cnt / 2; i < cnt; i++)
	{
		int d = dist(rand), p = smallDist(rand), q = smallDist(rand);
		int naiveRes = naiveSolve(d, p, q), res = solve(d, p, q);
		if (naiveRes != res)
		{
			cout << "Error! " << "d = " << d << ", p = " << p << ", q = " << q << "\n";
			cout << "naiveSolve: " << naiveRes << ", solve: " << res << "\n\n";
			errCnt++;
		}
	}
	cout << "Error Count: " << errCnt << "\n\n";
}

int main(void)
{
	// test(300);
	int d, p, q;
	cin >> d >> p >> q;
	cout << solve(d, p, q);
	return 0;
}