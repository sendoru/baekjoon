#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	long long ans = 0;
	cin >> n;
	vector<int> costs(2 << n);
	for (int i = 2; i < 2 << n; i++)
	{
		cin >> costs[i];
		ans += costs[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1 << i; j < 1 << (i + 1); j++)
		{
			int target = max(costs[2 * j], costs[2 * j + 1]);
			ans += target - min(costs[2 * j], costs[2 * j + 1]);
			costs[2 * j] = target;
			costs[2 * j + 1] = target;
			costs[j] += target;
		}
	}
	cout << ans;
	return 0;
}
