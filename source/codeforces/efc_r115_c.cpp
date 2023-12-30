#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		vector<ll> vec(n);
		ll vecSum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
			vecSum += vec[i];
		}

		if ((vecSum * 2ll) % vec.size() != 0ll)
		{
			cout << 0 << '\n';
			continue;
		}

		map<ll, ll> cnt;
		ll doubleAvg = (vecSum * 2ll) / vec.size();
		for (int i = 0; i < vec.size(); i++)
		{
			cnt[vec[i]]++;
		}
		ll ans = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] * 2 == doubleAvg)
			{
				ans += cnt[doubleAvg - vec[i]] - 1ll;
			}
			else
			{
				ans += cnt[doubleAvg - vec[i]];
			}
		}

		cout << ans / 2ll << '\n';
	}
	return 0;
}