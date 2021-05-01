#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int primeSize = 1003002;

	bool* isPrime = new bool[primeSize];
	bool* isPalindrome = new bool[primeSize];


	for (int i = 0; i < primeSize; i++)
	{
		isPrime[i] = true;
		isPalindrome[i] = true;
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

	for (int i = 1; i < primeSize; i++)
	{
		for (int j = 0; j <= to_string(i).length() / 2; j++)
		{
			if (to_string(i)[j] != to_string(i)[to_string(i).length() - j - 1])
			{
				isPalindrome[i] = false;
				break;
			}
		}
	}


	int min, tmp;

	cin >> min;

	for (int i = min; true; i++)
	{
		if (isPalindrome[i] == true && isPrime[i] == true)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}