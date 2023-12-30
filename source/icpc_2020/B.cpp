#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
constexpr ll MOD = 1000000007;

ll modPow(ll base, ll exp)
{
	if (exp == 1)
	{
		return base;
	}
	if (exp % 2 == 0)
	{
		return ((modPow(base, exp / 2) % MOD) * (modPow(base, exp / 2) % MOD)) % MOD;
	}
	if (exp % 2 == 1)
	{
		return ((modPow(base, exp / 2) % MOD) * (modPow(base, exp / 2) % MOD) * base) % MOD;
	}
}

int main(void)
{

}