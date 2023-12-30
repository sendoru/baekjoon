#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int q, query, x;
	cin >> q;
	multiset<int> a;
	deque<int> unsorted;
	vector<int> output;
	int aSize = 0, sortedCnt = 0;
	while(q--)
	{
		cin >> query;
		if (query == 1)
		{
			aSize++;
			cin >> x;
			unsorted.push_back(x);
		}
		else if (query == 2)
		{
			aSize--;
			if (sortedCnt != 0)
			{
				sortedCnt--;
				auto iter = a.begin();
				cout << *iter << '\n';
				a.erase(iter);
			}
			else
			{
				cout << unsorted.front() << '\n';
				a.erase(unsorted.front());
				unsorted.pop_front();
			}
		}
		else if (query == 3)
		{
			sortedCnt = aSize;
			while (!unsorted.empty())
			{
				a.insert(unsorted.front());
				unsorted.pop_front();
			}
		}
	}
	return 0;
}