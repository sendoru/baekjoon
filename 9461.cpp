#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long int P[101] = { 0, 1, 1, 1, 2, 2, 0, };

	for (int i = 6; i <= 100; i++)
	{
		P[i] = P[i - 1] + P[i - 5];
	}

	int T;
	
	cin >> T;

	int N[1000] = { 0, };
	for (int i = 0; i < T; i++)
	{
		cin >> N[i];
	}
	for (int i = 0; i < T; i++)
	{
		cout << P[N[i]] <<'\n';
	}
	return 0;
}

