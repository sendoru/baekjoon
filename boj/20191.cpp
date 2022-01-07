#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string s, t;
	cin >> s >> t;
	vector<vector<int>> pos(26);
	for (int i = 0; i < t.length(); i++)
	{
		pos[t[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (pos[s[i] - 'a'].size() == 0)
		{
			cout << -1;
			return 0;
		}
	}

	int ans = 1, idx = -1;
	for (int i = 0; i < s.length(); i++)
	{
		auto iter = upper_bound(pos[s[i] - 'a'].begin(), pos[s[i] - 'a'].end(), idx);
		if (iter == pos[s[i] - 'a'].end())
		{
			ans++;
			idx = -1;
			i--;
		}
		else
		{
			idx = *iter;
		}
	}
	cout << ans;
	return 0;
}