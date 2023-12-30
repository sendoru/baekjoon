#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
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

	int N, tmp, cnt = 0;
	vector<int> nums;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		nums.push_back(tmp);
	}

	for (int i = 0; i < N; i++)
	{
		if (isPrime[nums[i]] == true)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
}