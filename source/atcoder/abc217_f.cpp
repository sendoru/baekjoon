#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if ((y - x) % 2 == 1)
		{
			a.push_back({ x, y });
		}
	}
	sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) -> bool
		{
			if (a.second - a.first == b.second - b.first)
			{
				return a.first < b.first;
			}
			return a.second - a.first < b.second - b.first;
		});
	vector<vector<int>> dp(n, vector<int>(a.size()));
	vector<bool> mask(a.size());
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (a[i].first != a[j].first && a[i].first != a[j].second && a[i].second != a[j].first && a[i].second != a[j].second)
			{
				mask[i] = true;
			}
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		dp[n - 1][i] = 1;
	}
	for (int i = n - 1; i >= 0; i++)
	{
		for (int j = 0; j < a.size(); j++)
		{

		}
	}

	return 0;
}