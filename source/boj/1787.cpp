#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<int> getPartialMatch(string& p)
{
	int m = p.length();
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

vector<int> kmp(string& t, string& p)
{
	int n = t.length();
	int m = p.length();

	vector<int> ret;
	vector<int> pmt = getPartialMatch(p);

	int matched = 0;
	for (int i = 0; i < n; i++)
	{
		while (matched > 0 && t[i] != p[matched])
		{
			matched = pmt[matched - 1];
		}
		if (t[i] == p[matched])
		{
			matched++;
			if (matched == m)
			{
				ret.push_back(i - m + 1);
				matched = pmt[matched - 1];
			}
		}
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string t;
	cin >> t;
	vector<int> partialMatch = getPartialMatch(t);
	ll ans = 0;
	for (ll i = 1; i < partialMatch.size(); i++)
	{
		ll j = 0;
		while (j != 0 && t[i] != t[j])
			j = partialMatch[j];


	}
	cout << ans;
	return 0;
}