#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] -= i;
	}
	priority_queue<ll> pq;
	vector<ll> ans;
	for (int i = 0; i < n; i++)
	{
		if (!pq.empty() && pq.top() >= a[i])
		{
			pq.pop();
			pq.push(a[i]);
		}
		pq.push(a[i]);
		ans.push_back(pq.top());
	}
	for (ll i = ans.size() - 1; i >= 1; i--)
	{
		ans[i - 1] = min(ans[i], ans[i - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] + i << ' ';
	}
	return 0;
}