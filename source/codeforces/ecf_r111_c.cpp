#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3fffffff;

bool isGood(vector<ll>& a, int i1, int i2, int i3)
{
	if (!((a[i1] >= a[i2] && a[i2] >= a[i3]) || (a[i1] <= a[i2] && a[i2] <= a[i3])))
		return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		ll ans = 2 * n - 1;
		if (n >= 3)
		{
			for (int i = 0; i < n - 2; i++)
			{
				if (isGood(a, i, i + 1, i + 2))
				{
					ans++;
				}
			}
			for (int i = 0; i < n - 3; i++)
			{
				if (isGood(a, i, i + 1, i + 2) && isGood(a, i, i + 1, i + 3) && isGood(a, i, i + 2, i + 3) && isGood(a, i + 1, i + 2, i + 3))
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}