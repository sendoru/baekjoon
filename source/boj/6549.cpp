#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

vector<ll> solve(vector<ll>& h, vector<ll>& partialSum)
{
	vector<int> remaining;
	h.push_back(0);
	ll maxScore = 0, start = 0, end = 0;
	for (int i = 0; i < h.size(); i++)
	{
		while (!remaining.empty() && h[remaining.back()] >= h[i])
		{
			int j = remaining.back();
			ll width;
			remaining.pop_back();
			int cnt = -1;

			if (remaining.empty())
			{
				cnt = i;
				width = partialSum[i - 1];
			}
			else
			{
				cnt = i - remaining.back() - 1;
				width = partialSum[i - 1] - partialSum[remaining.back()];
			}
			if (h[j] * width > maxScore)
			{
				maxScore = h[j] * width;
				start = remaining.empty() ? 0 : remaining.back() + 1;
				end = i - 1;
			}
		}
		remaining.push_back(i);
	}

	return {maxScore, start, end};
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n;
	cin >> n;
	vector<ll> h(n);
	vector<ll> partialSum(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	partialSum[0] = h[0];
	for (int i = 1; i < n; i++)
	{
		partialSum[i] = partialSum[i - 1] + h[i];
	}
	vector<ll> ans = solve(h, partialSum);
	cout << ans[0] << '\n' << ans[1] + 1 << ' ' << ans[2] + 1 << '\n';

	return 0;
}