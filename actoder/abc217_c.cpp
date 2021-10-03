#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> p(n + 1);
	for (int i = 1; i <= n; i++)
	{
		p[i].second = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].first;
	}
	sort(p.begin() + 1, p.end());
	for (int i = 1; i <= n; i++)
	{
		cout << p[i].second << ' ';
	}
	return 0;
}