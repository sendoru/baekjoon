#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, c;
	cin >> n >> m >> c;
	multiset<int> bags;
	multiset<int> jewels;
	for (int i = 0; i < m; i++)
	{
		bags.insert(c);
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		jewels.insert(temp);
	}
	int ans = 0;
	while (!jewels.empty())
	{
		int cur = *jewels.begin();
		jewels.erase(jewels.begin());
		auto iter = bags.lower_bound(cur);
		if (iter == bags.end())
		{
			break;
		}
		int remain = *iter - cur;
		bags.erase(iter);
		bags.insert(remain);
		ans++;
	}
	cout << ans << '\n';
	return 0;
}