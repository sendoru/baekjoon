#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#define MAX 100000001

using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	set<int> palindromes;

	//1 ~ 3자리 펠린드롬. 1은 소수 아니라서 그냥 뺐음
	for (int i = 1; i <= 9; i++)
	{
		if (i != 1)
		{
			palindromes.insert(i);
		}
		palindromes.insert(i * 11);
		for (int j = 0; j <= 9; j++)
		{
			palindromes.insert(i * 101 + 10 * j);
		}
	}

	// 4 ~ 5자리 펠린드롬
	for (int i = 10; i <= 99; i++)
	{
		string tempstr = to_string(i);
		int temp = 10 * (tempstr[1] - '0') + tempstr[0] - '0';
		palindromes.insert(100 * i + temp);
		for (int j = 0; j <= 9; j++)
		{
			palindromes.insert(1000 * i + 100 * j + temp);
		}
	}

	//6 ~ 7자리
	for (int i = 100; i <= 999; i++)
	{
		string tempstr = to_string(i);
		int temp = 100 * (tempstr[2] - '0') + 10 * (tempstr[1] - '0') + tempstr[0] - '0';
		palindromes.insert(1000 * i + temp);
		for (int j = 0; j <= 9; j++)
		{
			palindromes.insert(10000 * i + 1000 * j + temp);
		}
	}

	//8자리
	/* for (int i = 1000; i <= 9999; i++)
	{
		string tempstr = to_string(i);
		int temp = 1000 * (tempstr[3] - '0') + 100 * (tempstr[2] - '0') + 10 * (tempstr[1] - '0') + tempstr[0] - '0';
		palindromes.insert(10000 * i + temp);
	} */

	vector<bool> isPrime(10001, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= 10000; i++)
	{
		if (isPrime[i])
		{
			for (int j = 2 * i; j * j <= 10000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	int min, max;

	cin >> min >> max;

	if (max > 10000000)
	{
		max = 10000000;
	}
	for (int i = min; i <= max; i++)
	{
		if (palindromes.find(i) != palindromes.end())
		{
			bool isiPrime = true;

			for (int j = 0; j * j <= i; j++)
			{
				if (isPrime[j])
				{
					if (i % j == 0)
					{
						isiPrime = false;
						break;
					}
				}
			}
			if (isiPrime)
			{
				cout << i << '\n';
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}