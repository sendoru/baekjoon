#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<bool> isPrime(151, true);
	vector<int> primes;
	vector<int> specialNums;
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= 150; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
			for (int j = 2; i * j <= 150; j++)
			{
				isPrime[i * j] = false;
			}
		}
	}
	for (int i = 0; i < primes.size() - 1; i++)
	{
		specialNums.push_back(primes[i] * primes[i + 1]);
	}

	int n;
	cin >> n;
	cout << *(upper_bound(specialNums.begin(), specialNums.end(), n));
	return 0;
}