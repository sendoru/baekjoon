#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, K, temp, count = 0;
	cin >> N >> K;
	vector<int> coins;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		coins.push_back(temp);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		count += K / coins[i];
		K %= coins[i];
	}

	cout << count << endl;

	return 0;
}