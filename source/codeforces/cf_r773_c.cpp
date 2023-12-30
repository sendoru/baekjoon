#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(12);

	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<pair<int, int>> a(n);
		for (auto& elem : a)
		{
			cin >> elem.first;
		}
		sort(a.begin(), a.end());
		auto iter = a.begin();
		while (iter != a.end())
		{
			if ((*iter).second == 1)
			{
				iter++;
				continue;
			}
			if (iter == a.end())
			{
				break;
			}
			auto nextIter = upper_bound(a.begin(), a.end(), make_pair((*iter).first * x, 0)) - 1;
			if (*nextIter == make_pair((*iter).first * x, 0))
			{
				(*iter).second = 1;
				(*nextIter).second = 1;
			}
			iter++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i].second == 0)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}