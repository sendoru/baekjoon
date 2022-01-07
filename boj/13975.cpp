#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll ans = 0;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll> > pq;
		for (int i = 0; i < n; i++)
		{
			ll temp;
			cin >> temp;
			pq.push(temp);
		}

		while (pq.size() > 1)
		{
			ll f1 = pq.top();
			pq.pop();
			ll f2 = pq.top();
			pq.pop();
			ans += f1 + f2;
			pq.push(f1 + f2);
		}

		cout << ans << '\n';
	}

	return 0;
}