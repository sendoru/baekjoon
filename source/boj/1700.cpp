#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> v(k);
	vector<bool> used(k + 1);
	vector<deque<int>> remain(k + 1);
	int usedCnt = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
		remain[v[i]].push_back(i);
	}


	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		remain[v[i]].pop_front();
		if (used[v[i]])
		{
			continue;
		}
		else if (usedCnt < n)
		{
			used[v[i]] = true;
			usedCnt++;
		}
		else
		{
			int unplug = -1;
			for (int j = 1; j <= k; j++)
			{
				if (used[j] && (unplug == -1 || remain[j].empty() || (!remain[j].empty() && !remain[unplug].empty() && remain[j] > remain[unplug])))
				{
					unplug = j;
				}
			}
			used[unplug] = false;
			used[v[i]] = true;
			ans++;
		}
	}

	cout << ans;
	return 0;
}