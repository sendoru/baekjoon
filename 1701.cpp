#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getMaxPartialMatch(string& p)
{
	int m = p.length(), ret = 0;

	for (int i = 1; i < m; i++)
	{
		vector<int > pmt(m, 0);
		int begin = i, matched = 0;
		while (begin + matched < m)
		{
			if (p[begin + matched] == p[matched + i - 1])
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
					begin += matched - pmt[matched + i - 2];
					matched = pmt[matched + i - 2];
				}
			}
		}
		ret = max(ret, *max_element(pmt.begin(), pmt.end()));
	}

	return ret;
}

int main(void)
{
	string s;
	cin >> s;
	cout << getMaxPartialMatch(s) << '\n';
	return 0;
}