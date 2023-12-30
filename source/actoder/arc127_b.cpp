#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> toTernary(int a, int len)
{
	vector<char> ret;
	while (a != 0)
	{
		ret.push_back(a % 3);
		a /= 3;
	}
	while (ret.size() < len)
	{
		ret.push_back(0);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l;
	cin >> n >> l;
	vector<vector<char>> s(n, vector<char>(l - 1));
	for (int i = 0; i < n; i++)
	{
		vector<char> back = toTernary(i, l - 1);
		cout << '2';
		for (auto elem : back)
			cout << (int)elem;
		cout << '\n';

		cout << '1';
		for (auto elem : back)
			cout << (int)(elem + 1) % 3;
		cout << '\n';

		cout << '0';
		for (auto elem : back)
			cout << (int)(elem + 2) % 3;
		cout << '\n';
	}
	return 0;
}