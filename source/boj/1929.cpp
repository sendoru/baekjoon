#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int primeSize = 100000001;
	bool* isPrime = new bool[primeSize];
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < primeSize; i++)
	{
		isPrime[i] = true;
	}

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

	int min, max, tmp;

	cin >> min >> max;

	for (int i = min; i < max + 1; i++)
	{
		if (isPrime[i] == true)
		{
			cout << i << '\n';
		}
	}
}