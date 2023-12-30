#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(12);

	int t;
	cin >> t;
	while (t--)
	{
		vector < pair < ll, ll> > p(3);
		for (int i = 0; i < 3; i++)
		{
			cin >> p[i].second >> p[i].first;
		}

		sort(p.begin(), p.end());
		if (p[1].first == p[2].first)
		{
			cout << p[2].second - p[1].second << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}