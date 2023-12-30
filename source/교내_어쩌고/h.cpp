#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double ld;

int solve(ll n)
{
	if (n <= 9) return 0;
	else if (n <= 99)
	{
		return n % 10 == 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << (n % 10 == 0 ? 1 : 0) << '\n';
	}
	return 0;
}