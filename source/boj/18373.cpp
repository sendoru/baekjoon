#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

ull modPow(ull b, ull e, ull m)
{
	ull tmp[32];
	tmp[0] = b % m;
	ull ret = 1;
	ull idx = 0;
	while (e != 0)
	{
		if (e & 1) ret *= tmp[idx];
		ret %= m;
		e >>= 1;
		idx++;
		tmp[idx] = tmp[idx - 1] * tmp[idx - 1] % m;
	}
	return ret;
}

ull modInv(ull b, ull p)
{
	return modPow(b, p - 2, p);
}

ull solve(ull n, ull k, ull p)
{
	if (n == 2) return n % p;
	if (n >= p) return 0;
	if (k >= 4 || (n >= 4 && k >= 3) || (n >= 13 && k >= 2)) return 0;
	// O(n)
	if (k == 1)
	{
		ull ret = 1;
		for (int i = 1; i <= n; i++)
		{
			ret = ret * i % p;
		}
		return ret;
	}
	// 가능한 경우: 3 <= n <= 12
	if (k == 2)
	{
		ull nxt = 1;
		for (ull i = 1; i <= n; i++)
		{
			nxt *= i;
		}
		if (nxt >= p) return 0;
		ull ret = 1;
		if (n != 12)
		{
			for (ull i = 1; i <= nxt; i++)
			{
				ret = ret * i % p;
			}
		}
		else
		{
			// (p - (12!))!
			// (p - 1)! == (p - 1) mod p
			// (p - 1)! = (p - (12!))! * (p + 1
			// (p - 2)! == 1 mod p
			ret = p - 1;
			ull den = 1;
			for (ull i = p - 1; i > nxt; i--)
			{
				den = den * i % p;
			}
			ret = ret * modInv(den, p) % p;
		}
		return ret;
	}
	// 가능한 유일한 경우: n == 3 && k == 3
	else
	{
		ull ret = 1;
		for (int i = 1; i <= 720; i++)
		{
			ret = ret * i % p;
		}
		return ret;
	}
	return -1;
}

int main(void)
{
	ull n, k, p;
	cin >> n >> k >> p;
	cout << solve(n, k, p);
	return 0;
}