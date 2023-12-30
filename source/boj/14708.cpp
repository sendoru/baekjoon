#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(void)
{
	ll k;
	cin >> k;
	ll x, y, z;
	auto isqrt = [](ll x) {
		ll lo = 1, hi = 1e9+10;
		while (lo + 1 < hi) {
			const ll mid = (lo + hi) / 2;
			if (mid * mid <= x)
				lo = mid;
			else
				hi = mid;
		}
		return lo;
	};
	ll mini = 9e18;
	vector<ll> ans(3);
	for (x = 1; (x-1)*(x-1)*(x-1) <= k; x++) {
		ll t = isqrt((k + x - 1) / x);
		for (z = max(t-1, 1LL); z <= t+1; ++z) {
			for (y = max((k / x + z - 1) / z - 1, 1LL); y <= (k / x + z - 1) / z + 1; ++y) {
				if (x * y * z < k)
					continue;
				if (mini >= x * y + y * z + z * x) {
					vector<ll> test = { x, y, z };
					sort(test.begin(), test.end());
					if (mini > x * y + y * z + z * x || test < ans)
						swap(test, ans);
					mini = x * y + y * z + z * x;
				}
			}
		}
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}