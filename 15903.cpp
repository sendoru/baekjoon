#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<long long int> cards(N);
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	for (int i = 0; i < M; i++)
	{
		sort(cards.begin(), cards.end());
		long long int temp = cards[0] + cards[1];
		cards[0] = temp;
		cards[1] = temp;
	}

	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += cards[i];
	}

	cout << sum << endl;
	return 0;
}