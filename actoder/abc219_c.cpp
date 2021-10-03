#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string x;
	cin >> x;
	vector<int> order(26), reversedOrder(26);
	for (int i = 0; i < x.size(); i++)
	{
		order[x[i] - 'a'] = i;
		reversedOrder[i] = x[i] - 'a';
	}

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
		{
			s[i][j] = order[s[i][j] - 'a'] + 'a';
		}
	}
	sort(s.begin(), s.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			s[i][j] = reversedOrder[s[i][j] - 'a'] + 'a';
		}
	}

	for (string elem : s)
	{
		cout << elem << '\n';
	}

	return 0;
}