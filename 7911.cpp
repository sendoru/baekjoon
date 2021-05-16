#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, temp, cnt = 0;
	cin >> n >> k;

	vector<int> laundries;
	multiset<int> clothespins;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		laundries.push_back(temp);
	}

	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		clothespins.insert(temp);
	}

	if (n > k)
	{
		cout << "NIE" << '\n';
		return 0;
	}
	
	sort(laundries.begin(), laundries.end(), greater<int>());

	auto iter = clothespins.end();
	for (auto elem : laundries)
	{
		iter = clothespins.lower_bound(elem * 5);
		if (iter != clothespins.end())
		{
			cnt++;
			clothespins.erase(iter);
			continue;
		}

		iter = clothespins.lower_bound(elem * 3);
		if (iter != clothespins.end())
		{
			cnt++;
			clothespins.erase(iter);
		}
		else
		{
			cout << "NIE" << '\n';
			return 0;
		}
		
		iter = clothespins.lower_bound(elem * 2);
		if (iter != clothespins.end())
		{
			cnt++;
			clothespins.erase(iter);
			continue;
		}

		cout << "NIE" << '\n';
		return 0;

	}

	cout << cnt << '\n';

	return 0;
}