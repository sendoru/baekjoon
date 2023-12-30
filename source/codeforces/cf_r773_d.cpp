#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(12);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		deque<int> a(n);
		map<int, int> aa;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			aa[a[i]]++;
		}

		if (n % 2 == 1)
		{
			cout << -1 << '\n';
			continue;
		}

		bool possible = true;
		vector<pair<int, int>> queries;
		vector<int> d;
		int popedCnt = 0;
		while (!a.empty())
		{
			int prevSize = a.size();
			for (int i = 1; i <= a.size() / 2; i++)
			{
				int matchedSize = i;
				for (int j = 0; j < i; j++)
				{
					if (a[j] != a[j + i])
					{
						matchedSize = j;
						break;
					}
				}
				if (matchedSize == i)
				{
					d.push_back(2 * i);
					for (int j = 0; j < 2 * i; j++)
					{
						a.pop_front();
						popedCnt++;
					}
					break;
				}
				else if (matchedSize != 0)
				{
					vector<int> added;
					d.push_back(2 * i);
					for (int j = matchedSize; j < i; j++)
					{
						added.push_back(a[j]);
						queries.push_back({ j + i + popedCnt, a[j] });
					}
					for (int j = 0; j < i + matchedSize; j++)
					{
						a.pop_front();
						popedCnt++;
					}
					for (int elem : added)
					{
						a.push_front(elem);
						popedCnt++;
					}
					break;

				}

				else
				{
					bool reversedMatch = true;
					for (int j = 0; j < i; j++)
					{
						if (a[j] != a[2 * i - 1 - j])
						{
							reversedMatch = false;
							break;
						}
					}
					if (reversedMatch)
					{
						d.push_back(4 * i);
						for (int j = i; j < i * 2; j++)
						{
							queries.push_back({ j + popedCnt, a[j] });
						}
						for (int j = 0; j < i * 2; j++)
						{
							a.pop_front();
							popedCnt += 2;
						}
						break;
					}
				}

				if (prevSize != a.size())
				{
					break;
				}
			}


			if (prevSize == a.size())
			{
				possible = false;
				break;
			}
		}

		if (!possible)
		{
			cout << -1 << '\n';
		}
		else
		{
			// cout << '\n';
			// cout << "Q size: ";
			cout << queries.size() << '\n';
			for (auto& elem : queries)
			{
				cout << elem.first << ' ' << elem.second << '\n';
			}
			// cout << '\n';
			// cout << "D size: ";
			cout << d.size() << '\n';
			for (auto elem : d)
			{
				cout << elem << '\n';
			}
		}
	}
	return 0;
}