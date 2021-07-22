#include <iostream>
#include <set>
#include <queue>

typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	priority_queue<pair<ll, ll>> jewels;
	multiset<ll> bags;
	for (int i = 0; i < n; i++)
	{
		pair<ll, ll> temp;
		cin >> temp.second >> temp.first;
		jewels.push(temp);
	}
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		bags.insert(temp);
	}
	ll ans = 0;
	while (!jewels.empty() && !bags.empty())
	{
		pair<ll, ll> curJewel = jewels.top();
		jewels.pop();
		auto iter = bags.lower_bound(curJewel.second);
		if (iter != bags.end())
		{
			ans += curJewel.first;
			bags.erase(iter);
		}
	}
	cout << ans << '\n';
	return 0;
}