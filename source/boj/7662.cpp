#include <iostream>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		multiset<int> ms;
		ms.clear();
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			char q1; int q2;
			cin >> q1 >> q2;
			if (q1 == 'D')
			{
				if (ms.size() != 0)
				{
					if (q2 == 1)
					{
						ms.erase(ms.find(*(--(ms.end()))));
					}
					else
					{
						ms.erase(ms.find(*ms.begin()));
					}
				}
			}
			else
			{
				ms.insert(q2);
			}
		}
		if (ms.size() == 0)
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			cout << *(--(ms.end())) << ' ' << *ms.begin() << endl;
		}
	}
	return 0;
}