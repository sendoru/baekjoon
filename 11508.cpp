#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> daires(N);
	for (int i = 0; i < N; i++)
	{
		cin >> daires[i];
	}

	sort(daires.begin(), daires.end(), greater<int>());

	long long int cost = 0;

	for (int i = 0; i < N; i++)
	{
		if (i % 3 != 2)
		{
			cost += daires[i];
		}
	}

	cout << cost << endl;
	return 0;
}