#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

ll solve(vector<ll>& h)
{
	vector<int> remaining;
	h.push_back(0);
	ll ret = 0;
	for (int i = 0; i < h.size(); i++)
	{
		while (!remaining.empty() && h[remaining.back()] >= h[i])
		{
			int j = remaining.back();
			remaining.pop_back();
			int width = -1;

			if (remaining.empty())
			{
				width = i;
			}
			else
			{
				width = i - remaining.back() - 1;
			}
			ret = max(ret, h[j] * width);
		}
		remaining.push_back(i);
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<ll> h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	cout << solve(h) << '\n';

	return 0;
}