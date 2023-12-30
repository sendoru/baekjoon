#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ll n, ans = 0;
	cin >> n;
	vector<ll> v;
	for (int i = 0; i < n; i++)
	{
		ll cur;
		cin >> cur;
		while (!v.empty() && v.back() < cur)
		{
			v.pop_back();
			ans++;
		}
		if (!v.empty()) ans += max(1ll, min((ll)v.size(), 1 + (ll)(v.end() - lower_bound(v.begin(), v.end(), cur, greater<ll>()))));
		v.push_back(cur);
	}

	cout << ans;
	return 0;
}