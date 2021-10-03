#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long double ld;

int main(void)
{
	int n, m;
	cin >> n >> m;
	ld delta = 0.0000001;
	vector<pair<ld, ld>> ab(m);
	for (int i = 0; i < m; i++)
	{
		cin >> ab[i].first >> ab[i].second;
		ld grad = ab[i].second - ab[i].first;
		ab[i].first -= grad * delta;
		ab[i].second += grad * delta;
	}

	sort(ab.begin(), ab.end());
	vector<ld> cache;
	for (int i = 0; i < ab.size(); i++)
	{
		if (cache.empty() || cache.back() < ab[i].second)
		{
			cache.push_back(ab[i].second);
		}
		else
		{
			auto iter = lower_bound(cache.begin(), cache.end(), ab[i].second);
			*iter = ab[i].second;
		}
	}

	cout << cache.size();
	return 0;
}