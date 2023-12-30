#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < n; i++)
		{
			ll temp;
			cin >> temp;
			pq.push(temp);
		}
		ll ans = 1;
		while (pq.size() > 1)
		{
			ll top1, top2;
			top1 = pq.top() % MOD;
			pq.pop();
			top2 = pq.top() % MOD;
			pq.pop();

			ans = ((ans * top1) % MOD) * top2 % MOD;

			pq.push(top1 * top2);
		}

		cout << ans << '\n';
	}


	return 0;
}