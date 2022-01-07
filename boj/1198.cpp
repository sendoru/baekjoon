#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> straws(N);

	for (int i = 0; i < N; i++)
	{
		cin >> straws[i];
	}

	sort(straws.begin(), straws.end(), greater<int>());

	for (int i = 0; i < N - 2; i++)
	{
		if (straws[i] < straws[i + 1] + straws[i + 2])
		{
			cout << straws[i] + straws[i + 1] + straws[i + 2] << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}