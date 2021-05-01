#include <iostream>
#include <vector>

using namespace std;



int main(void)
{
	vector<bool> isPrime(100001);
	vector<int> primeFactorCounter(100001);

	isPrime[0] = false;
	isPrime[1] = false;
	primeFactorCounter[0] = 0;
	primeFactorCounter[1] = 0;
	for (int i = 2; i <= 100000; i++)
	{
		isPrime[i] = true;
		primeFactorCounter[i] = 1;
	}

	for (int i = 2; i * i <= 100000; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = i * 2; j <= 100000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	int A, B, cnt = 0;
	cin >> A >> B;

	for (int i = 2; i <= B; i++)
	{
		if (isPrime[i])
			continue;

		for (int divisor = i / 2; divisor > 1; divisor--)
		{
			if (i % divisor == 0)
			{
				primeFactorCounter[i] = primeFactorCounter[divisor] + 1;
				break;
			}
		}
	}
		
	for (int i = A; i <= B; i++)
	{
		if (isPrime[primeFactorCounter[i]] == true)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}