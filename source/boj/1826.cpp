#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > stations;
	priority_queue<int, vector<int>, less<int> > fuels;

	for (int i = 0; i < N; i++)
	{
		int distance, amountofFuel;
		cin >> distance >> amountofFuel;
		stations.push({ distance, amountofFuel });
	}

	int sumofDistance, initialFuel, sumofFuel;
	cin >> sumofDistance >> initialFuel;
	sumofFuel = initialFuel;

	int ans = 0;
	while (sumofFuel < sumofDistance)
	{
		if ((stations.empty() || stations.top().first > sumofFuel) && fuels.empty())
		{
			ans = -1;
			break;
		}
		while (!stations.empty() && stations.top().first <= sumofFuel)
		{
			int amountofFuel = stations.top().second;
			stations.pop();
			fuels.push(amountofFuel);
		}
		if (!fuels.empty())
		{
			sumofFuel += fuels.top();
			fuels.pop();
			ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}