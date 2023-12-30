#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, h;
		cin >> n >> h;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end(), greater<int>());

		int ans = 0;
		ans += 2 * (h / (a[0] + a[1]));
		h -= (ans / 2) * (a[0] + a[1]);
		if (h > 0)
		{
			ans++;
			h -= a[0];
		}
		if (h > 0)
		{
			ans++;
			h -= a[1];
		}

		cout << ans << '\n';
	}

	return 0;
}