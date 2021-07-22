#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		pair<int, int> a, b, f;
		cin >> a.first >> a.second;
		cin >> b.first >> b.second;
		cin >> f.first >> f.second;
		if (a.first == b.first && a.first == f.first && ((a.second < f.second && f.second < b.second) || (a.second > f.second && f.second > b.second)))
		{
			cout << abs(a.second - b.second) + 2 << '\n';
		}
		else if (a.second == b.second && a.second == f.second && ((a.first < f.first && f.first < b.first) || (a.first > f.first && f.first > b.first)))
		{
			cout << abs(a.first - b.first) + 2 << '\n';
		}
		else
		{
			cout << abs(a.first - b.first) + abs(a.second - b.second) << '\n';
		}
	}

	return 0;
}