#include <iostream>

using namespace std;

int main(void)
{
	long long int primeSize = 123457 * 2;

	bool* isPrime = new bool[primeSize];

	for (int i = 0; i < primeSize; i++)
	{
		isPrime[i] = true;
	}

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i <= primeSize; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = 2; i * j < primeSize; j += 1)
			{
				isPrime[i * j] = false;
			}
		}
	}

	int N = -1, cnt;

	while (true)
	{
		cnt = 0;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (isPrime[i] == true)
				cnt++;
		}
		cout << cnt << '\n';

	}
}