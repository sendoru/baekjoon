#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <random>
#define DEBUG
#undef DEBUG
using namespace std;
typedef long long ll;
constexpr ll INF = 2e9;
constexpr ll MOD = 1e9 + 7;

vector<int> getPartialMatch(vector<ll>& p)
{
	int m = p.size();
	vector<int> pmt(m);

	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (p[begin + matched] == p[matched])
		{
			matched++;
			pmt[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
			{
				begin++;
			}
			else
			{
				begin += matched - pmt[matched - 1];
				matched = pmt[matched - 1];
			}
		}
	}

	return pmt;
}

bool verdict(vector<ll>& v, int k, int p)
{
	for (int i = k; i < v.size(); i += p)
	{
		int curIdx = i;
		for (curIdx; curIdx - i < p; curIdx++)
		{
			if (curIdx >= v.size())
				break;
			if (v[curIdx] != v[curIdx - i + k])
			{
				return false;
			}
		}
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 6 1 2 5 3 4
	// 0 0 3 1 5 7
	// 0 0 0 4 2 3
	// 0 0 3 1 5 7
	// 0 0 0 4 2 3
	// 0 0 3 1 5 7

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& elem : v)
		cin >> elem;

	reverse(v.begin(), v.end());
	auto pm = getPartialMatch(v);

	// k
	int k = 0, p = pm.size() - pm.back();;


	pair<int, int> ans = { k, p };
	while (!pm.empty())
	{
		pm.pop_back();
		k++;
		if (pm.size() != 0)
			p = pm.size() - pm.back();
		else
			p = 0;

		if (k + p < ans.first + ans.second || (k + p == ans.first + ans.second && p < ans.second))
		{
			ans = { k, p };
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';

#ifdef DEBUG
	cout << "Failure Function: ";
	for (auto& elem : pm)
		cout << elem << ' ';
	cout << '\n';

	reverse(v.begin(), v.end());

	for (int t = 0; t < 100; t++)
	{
		v = vector<ll>(20);
		for (auto& elem : v)
			elem = rand() % 12;

		reverse(v.begin(), v.end());
		auto pm = getPartialMatch(v);

		while (!pm.empty() && pm.back() == 0)
		{
			pm.pop_back();
		}

		// k
		int k = v.size() - pm.size();
		// p
		int p = 0;
		if (pm.size() != 0)
			p = pm.size() - pm.back();
		pair<int, int> ans = { k, p };

		while (!pm.empty())
		{
			pm.pop_back();
			k++;
			if (pm.size() != 0)
				p = pm.size() - pm.back();

			if (k + p < ans.first + ans.second || (k + p == ans.first + ans.second && p < ans.second))
			{
				ans = { k, p };
			}
		}

		cout << ans.first << ' ' << ans.second << '\n';

		reverse(v.begin(), v.end());
		cout << (verdict(v, ans.first, ans.second) ? "" : "NO") << '\n';
	}

#endif

	return 0;
}