#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	vector<int> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		p[a[i].second] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << ' ';
	}
	return 0;
}