#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
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
		int n;
		cin >> n;
		vector<ll> a(n);
		map<ll, ll> aa;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			aa[a[i]] += 1;
		}
		for (int i = 1; i <= n; i++)
		{
			cout << max(i, (int)aa.size()) << ' ';
		}
		cout << '\n';
	}
	return 0;
}