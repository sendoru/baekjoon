#include <iostream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	map<int, vector<int>> order;
	for (int i = 1; i <= n; i++)
	{
		order[a[i]].push_back(i);
	}

	for (int i = 0; i < q; i++)
	{
		int x, k;
		cin >> x >> k;
		k--;
		// cout << "ans: ";
		if (order.find(x) == order.end() || order[x].size() <= k) cout << -1 << '\n';
		else cout << order[x][k] << '\n';
	}

	return 0;
}