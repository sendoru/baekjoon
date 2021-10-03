#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> order(n);
	vector<vector<int>> passports(k);
	for (int i = 0; i < n; i++) cin >> order[i];
	bool valid = true;
	for (int i = order.size() - 1; i >= 0; i--)
	{
		int chosen = -1;
		for (int j = 0; j < passports.size(); j++)
		{
			if (chosen == -1
				&& (passports[j].empty() || passports[j].back() > order[i])) chosen = j;
			else if (chosen != -1
				&& !passports[j].empty()
				&& passports[j].back() > order[i]
				&& (passports[chosen].empty() || passports[chosen].back() > passports[j].back())) chosen = j;
		}
		if (chosen == -1)
		{
			valid = false;
			break;
		}
		else
		{
			passports[chosen].push_back(order[i]);
		}
	}

	cout << (valid ? "YES" : "NO");
	return 0;
}