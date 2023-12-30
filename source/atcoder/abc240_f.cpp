#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
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
		int n, m;
		cin >> n >> m;
		vector<ll> x(n), y(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}

		ll ans = max(x[0], x[0] * y[0] * (y[0] + 1) / 2);
		ll curA = x[0] * (y[0] * (y[0] + 1)) / 2, curB = x[0] * y[0];
		for (int i = 1; i < n; i++)
		{
			if (curB > 0 && x[i] < 0)
			{
				ll tempA = curA;
				ll bound = curB / (-x[i]);
				if (bound < y[i])
				{
					tempA += (curB * bound) + (x[i] * bound * (bound + 1) / 2);
					ans = max(ans, tempA);
				}
			}
			curA += (curB * y[i]) + (x[i] * y[i] * (y[i] + 1) / 2);
			ans = max(ans, curA);
			curB += x[i] * y[i];
		}


		// cout << "ans:";
		cout << ans << '\n';
		cout << '\n';
	}

	return 0;
}