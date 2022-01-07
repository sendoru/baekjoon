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
	vector<ll> a(n), b;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] -= i;
	}
	priority_queue<ll> pq;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (!pq.empty() && pq.top() >= a[i])
		{
			ans += pq.top() - a[i];
			pq.pop();
			pq.push(a[i]);
		}
		pq.push(a[i]);
	}
	cout << ans << '\n';
	return 0;
}