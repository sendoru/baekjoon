#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
typedef long double ld;
typedef long long ll;
const ld INF = 1e9;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> s(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> s[i];
	}

	vector<ll> x(m);
	for (int i = 0; i < m; i++)
	{
		cin >> x[i];
	}

	vector<ll> a(n);
	for (int i = 1; i < n; i++)
	{
		a[i] = s[i - 1] - a[i - 1];
	}

	unordered_map<ll, ll> evens, odds;
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
		{
			odds[a[i]]++;
		}
		else
		{
			evens[a[i]]++;
		}
	}

	ll ans = 0;
	for (auto curBase : evens)
	{
		for (auto xi : x)
		{
			ll curCnt = 0;
			// curBase.first + a0 = xi가 되도록 a0의 값을 조절
			ll a0 = xi - curBase.first;
			for (auto xj : x)
			{
				if (evens.find(xj - a0) != evens.end())
				{
					curCnt += evens[xj - a0];
				}
				if (odds.find(xj + a0) != odds.end())
				{
					curCnt += odds[xj + a0];
				}
			}
			ans = max(ans, curCnt);
		}
	}

	for (auto curBase : odds)
	{
		for (auto xi : x)
		{
			ll curCnt = 0;
			// curBase.first - a0 = xi가 되도록 a0의 값을 조절
			ll a0 = curBase.first - xi;
			for (auto xj : x)
			{
				if (evens.find(xj - a0) != evens.end())
				{
					curCnt += evens[xj - a0];
				}
				if (odds.find(xj + a0) != odds.end())
				{
					curCnt += odds[xj + a0];
				}
			}
			ans = max(ans, curCnt);
		}
	}

	cout << ans;


	return 0;
}