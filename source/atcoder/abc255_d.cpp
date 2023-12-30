#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
typedef long double ld;
typedef long long ll;
const ld INF = 1e9;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for (ll& elem : a)
		cin >> elem;

	sort(a.begin(), a.end());
	vector<ll> aSum(n);
	aSum[0] = a[0];
	for (int i = 1; i < n; i++)
		aSum[i] = aSum[i - 1] + a[i];

	for (int i = 0; i < q; i++)
	{
		ll x;
		cin >> x;
		auto lb = lower_bound(a.begin(), a.end(), x);
		auto ub = upper_bound(a.begin(), a.end(), x);
		ll lessCnt = lb - a.begin();
		ll greaterCnt = a.end() - ub;
		ll ans = 0;
		if (lessCnt > 0)
		{
			ans += x * lessCnt - aSum[lessCnt - 1];
		}
		if (greaterCnt > 0)
		{
			if (greaterCnt == a.size())
			{
				ans += aSum.back() - greaterCnt * x;
			}
			else
			{
				ll excluded = a.size() - greaterCnt;
				ans += aSum.back() - aSum[excluded - 1] - greaterCnt * x;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}