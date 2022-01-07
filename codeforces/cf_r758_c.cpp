#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
constexpr ll INF = 1e10;

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
		vector<ll> a(n), b(n);
		vector<bool> winable(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		// first: 공격력, second: 번호
		vector<pair<ll, ll>> sortedA(n), sortedB(n);
		for (int i = 0; i < n; i++)
		{
			sortedA[i] = { a[i], i };
			sortedB[i] = { b[i], i };
		}
		sort(sortedA.begin(), sortedA.end(), greater<pair<ll, ll>>());
		sort(sortedB.begin(), sortedB.end(), greater<pair<ll, ll>>());
		ll aLowerBound = INF, bLowerBound = INF;
		auto aIter = sortedA.begin(), bIter = sortedB.begin();

		winable[sortedA[0].second] = true;
		bLowerBound = b[sortedA[0].second];

		winable[sortedB[0].second] = true;
		aLowerBound = a[sortedB[0].second];

		while (true)
		{
			auto aLowerBoundIter = lower_bound(sortedA.begin(), sortedA.end(), make_pair(aLowerBound, 0), greater<pair<ll, ll>>());
			auto bLowerBoundIter = lower_bound(sortedB.begin(), sortedB.end(), make_pair(bLowerBound, 0), greater<pair<ll, ll>>());

			if (aLowerBoundIter == aIter && bLowerBoundIter == bIter) break;
			for (auto iter = aIter; iter < aLowerBoundIter; iter++)
			{
				auto cur = *iter;
				winable[cur.second] = true;
				bLowerBound = min(bLowerBound, b[cur.second]);
			}
			for (auto iter = bIter; iter < bLowerBoundIter; iter++)
			{
				auto cur = *iter;
				winable[cur.second] = true;
				aLowerBound = min(aLowerBound, a[cur.second]);
			}
			aIter = aLowerBoundIter;
			bIter = bLowerBoundIter;
		}

		for (int i = 0; i < n; i++)
		{
			cout << winable[i] ? 1 : 0;
		}
		cout << '\n';
	}

	return 0;
}