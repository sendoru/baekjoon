#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	string ans = "Aoki";

	for (int i = a; i <= b; i++)
	{
		bool primeAble = false;
		for (int j = c; j <= d; j++)
		{
			if (isPrime(i + j))
			{
				primeAble = true;
				break;
			}
		}
		if (!primeAble)
		{
			ans = "Takahashi";
			break;
		}
	}

	cout << ans;
	return 0;
}