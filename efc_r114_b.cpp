#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		vector<ll> abc(3);
		ll m;
		cin >> abc[0] >> abc[1] >> abc[2] >> m;
		sort(abc.begin(), abc.end());
		bool ans = true;

		if (m > abc[0] + abc[1] + abc[2] - 3)
			ans = false;

		if (m < abc[2] - abc[1] - abc[0] - 1)
			ans = false;

		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}