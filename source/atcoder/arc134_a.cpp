#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, l, w;
	cin >> n >> l >> w;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll ans = 0;
	sort(a.begin(), a.end());
	if (a[0] != 0)
	{
		a.insert(a.begin(), 0);
		ans++;
	}
	if (a.back() != l - w)
	{
		a.push_back(l - w);
		ans++;
	}
	for (int i = 0; i < a.size() - 1; i++)
	{
		ans += (a[i + 1] - a[i]) / w;
		if ((a[i + 1] - a[i]) % w == 0)
		{
			ans--;
		}
	}

	cout << ans;
	return 0;
}